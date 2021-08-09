#include "Johnson.h"
#include "Dijkstra.h"

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

Johnson::Johnson(TestCase &testCase) {
    adjList = &testCase.adjList;
    numVerticies = adjList->size();
    distances.resize(numVerticies);
    timeTaken = 0.0;
}

int Johnson::getVert()
{
    return numVerticies;
}

// Part of the Dijkstra implementation
// Returns the index of the node with the smallest distance that hasn't been visited
int Johnson::findShortestUnvisited(vector<bool>& hasVisited, vector<int>& distances) {
    int distanceOfSmallest = INF;
    int indexOfSmallest;

    for (size_t i = 0; i < this->numVerticies; i++) {
        if (hasVisited.at(i) == false && distances.at(i) <= distanceOfSmallest) {
            distanceOfSmallest = distances.at(i);
            indexOfSmallest = i;
        }
    }
    
    return indexOfSmallest;
}

bool Johnson::findShortestPaths() 
{   

    // Not part of implementation.
    vector<vector<Edge>> JohnList = *adjList;
    JohnList.resize(numVerticies + 1);
    vector<int> tempDist(numVerticies + 1);

    auto start = chrono::high_resolution_clock::now();
    
    // set all distancs to "infinity"
    for (int i = 0; i < numVerticies + 1; i++)
    {
        tempDist[i] = __INT_MAX__;
    }

    // add new node to graph with zero-weight edge to all vertices
    for (int i = 0; i < numVerticies; i++)
    {
        JohnList[numVerticies].push_back({i, 0});

    }

    // new node has weight zero
    tempDist[numVerticies] = 0; 

    // Apply Bellman Ford to calculate minimum weight on each vertex
    // Copied from Bellman Ford -------------------------------------//
    for (int i = 0; i < numVerticies; i++) 
    {
        for (size_t i = 0; i < JohnList.size(); i++) 
        {
            for (size_t j = 0; j < JohnList.at(i).size(); j++) 
            {
                int dest = JohnList.at(i).at(j).dest;
                int weight = JohnList.at(i).at(j).weight;
                if (tempDist[i] != __INT_MAX__ && tempDist[i] + weight < tempDist[dest]) 
                {
                    tempDist[dest] = tempDist[i] + weight;
                }
            }
        }
    }

    // check for negative cycles
    for (size_t i = 0; i < JohnList.size(); i++)
    {
        for (size_t j = 0; j < JohnList.at(i).size(); j++)
        {
            int dest = JohnList.at(i).at(j).dest;
            int weight = JohnList.at(i).at(j).weight;
            if (tempDist[i] != __INT_MAX__ && tempDist[i] + weight < tempDist[dest]) 
            {
                auto stop = chrono::high_resolution_clock::now();
                chrono::duration<double, std::milli> time = stop - start;
                timeTaken = time.count();
                return false;
            } 
        }
    }
    // --------------------------------------------------------------//
    
    // remove zero weighted node
    JohnList.resize(numVerticies);

    // calculate positive graph weights
    // w (a, b) = w(a, b) + h(a) - h(b)
    for (int i = 0; i < numVerticies; i++) 
    {
        for (size_t j = 0; j < JohnList.at(i).size(); j++) 
        {
            JohnList.at(i).at(j).weight += tempDist[i] - tempDist[JohnList.at(i).at(j).dest];
        }
    }

    // Run Dijkstra for all edges
    // Copied from Dijkstra -----------------------------------------//
    for (int src = 0; src < numVerticies; src++)
    {
        // Initialize our distances array to INF (to indicate not yet reachable)
        for(size_t i = 0; i < distances.size(); i++) {
            distances[i] = INF;
        }

        vector<bool> hasVisited(adjList->size(), false); // initialize to false

        distances[src] = 0; // source node is reachable to itself duh... right?

        for (size_t v = 0; v < this->numVerticies - 1; v++) {
            int currentNode = findShortestUnvisited(hasVisited, distances);
            hasVisited[currentNode] = true;

            for (size_t i = 0; i < adjList->at(currentNode).size(); i++) {
                Edge edge = adjList->at(currentNode).at(i);

                int newPathWeight = edge.weight + distances[currentNode];
                if (!hasVisited[edge.dest] && distances.at(currentNode) != INF && newPathWeight < distances.at(edge.dest)) {
                    distances[edge.dest] = newPathWeight;
                }
            }
        }

        distPositive.push_back(distances);
    }
    // --------------------------------------------------------------//

    for (size_t i = 0; i < distPositive.size(); i++) 
    {
        for (size_t j = 0; j < distPositive.at(i).size(); j++) 
        {
            if (distPositive.at(i).at(j) == -1)
            {
                distPositive.at(i).at(j) = INF;
            }
            else
            {
                distPositive.at(i).at(j) += tempDist[j] - tempDist[i];
            }
        }
    }

    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> time = stop - start;
    timeTaken = time.count();
    return true;
}

void Johnson::printDistances() {
    cout<<"Distance Matrix\n";
    for(size_t i = 0; i < distPositive.size(); i++) {
        cout << "\t" << i;    
    }
    cout<<endl;
    for (size_t i = 0; i < distPositive.size(); i++)
    {
        cout << i << "|\t";
        for (size_t j = 0; j < distPositive.at(i).size(); j++)
        {
            if (distPositive.at(i).at(j) == INF)
            {
                cout<<"INF\t";
            }
            else
            {
                cout<<distPositive.at(i).at(j)<<"\t";
            }
        }
        cout<<endl;
    }
}