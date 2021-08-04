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
    //distPositive = vector<vector<int>>(adjList->size(), vector<int>(adjList->size(), INF));
}

int Johnson::getVert()
{
    return numVerticies;
}

// Part of the Dijkstra implementation
int findShortestUnvisited(vector<bool>& hasVisited, vector<int>& distances) 
{
    int indexOfSmallest = -1;
    int distanceOfSmallest = -1;

    // First, find the first unvisited node
    size_t i; // index
    for(i = 0; i < distances.size(); i++) 
    {
        // Note: distance of -1 implies not reachable yet and not a candidate for next step in Dijkstra's
        if(hasVisited[i] == false && distances[i] != -1) { 
            indexOfSmallest = i;
            distanceOfSmallest = distances[i];
            break;
        }
    }

    // Now we can start comparing the other unvisited nodes
    // Note: distance of -1 implies not reachable yet and not a candidate for next step in Dijkstra's
    for(i = i + 1; i < distances.size(); i++) 
    {
        if(hasVisited[i] == false && distances[i] != -1 && distances[i] < distanceOfSmallest) {
            indexOfSmallest = i;
            distanceOfSmallest = distances[i];
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
        // Initialize our distances array to -1 (to indicate not yet reachable)
        for(size_t i = 0; i < distances.size(); i++) 
        {
            distances[i] = -1;
        }

        vector<bool> hasVisited(JohnList.size(), false); // initialize to false

        // analyze the first node
        distances[src] = 0; // source node is reachable to itself duh... right?
        for(size_t i = 0; i < JohnList.at(src).size(); i++) 
        {
            distances[JohnList.at(src).at(i).dest] = JohnList.at(src).at(i).weight;
        }
        hasVisited[src] = true;

        int currentNode = findShortestUnvisited(hasVisited, distances);
        
        // analyze the rest of the nodes, which is basically the same as above
        // This is about O(V*E) currently. If you have time and energy, it may be worth
        // using a min-queue instead of scanning array to find next node.
        while(currentNode != -1) 
        {
            for(size_t i = 0; i < JohnList.at(currentNode).size(); i++) 
            {
                int newPathWeight = JohnList.at(currentNode).at(i).weight + distances[currentNode];
                if(distances[JohnList.at(currentNode).at(i).dest] == -1 || distances[JohnList.at(currentNode).at(i).dest] > newPathWeight) 
                { // was currently unreachable
                    distances[JohnList.at(currentNode).at(i).dest] = newPathWeight;
                }
            }
            hasVisited[currentNode] = true;
            currentNode = findShortestUnvisited(hasVisited, distances);

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