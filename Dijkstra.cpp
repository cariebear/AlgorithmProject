#include "Dijkstra.h"

#include <iostream>
#include <chrono>

using namespace std;

Dijkstra::Dijkstra(TestCase &testCase) {
    adjList = &testCase.adjList;
    numVerticies = adjList->size();
    distances.resize(numVerticies);
    timeTaken = 0.0;
}

bool Dijkstra::findShortestPathsFromSource(int src) {
    // Sanity Check; cannot run Dijkstra's on graphs with negative weights
    // Don't time this part of the algorithm, as it is not a part of Dijkstra
    // O(E)
    for(size_t i = 0; i < adjList->size(); i++) {
        for(size_t j = 0; j < adjList->at(i).size(); j++) {
            if(adjList->at(i).at(j).weight < 0) {
                //cout << "Sorry! Cannot run Dijkstra's Algorithm with negative weights." << endl;
                return false;
            }
        }
    }

    auto start = chrono::high_resolution_clock::now();

    // Initialize our distances array to -1 (to indicate not yet reachable)
    for(size_t i = 0; i < distances.size(); i++) {
        distances[i] = INF;
    }

    vector<bool> hasVisited(adjList->size(), false); // initialize to false

    // analyze the first node
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

    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> time = stop - start;
    timeTaken = time.count();
    return true;
}

// Returns the index of the node with the smallest distance that hasn't been visited
int Dijkstra::findShortestUnvisited(vector<bool>& hasVisited, vector<int>& distances) {
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

void Dijkstra::printDistances() {
    printf("Vertex\t\t Distance from Source\n");
    for (int i = 0; i < numVerticies; i++) {
        if(distances[i] == INF) {
            printf("%d \t\t INF\n", i);
        }
        else {
            printf("%d \t\t %d\n", i, distances[i]);
        }
    }
}