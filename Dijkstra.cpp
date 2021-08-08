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
        distances[i] = -1;
    }

    vector<bool> hasVisited(adjList->size(), false); // initialize to false

    // analyze the first node
    distances[src] = 0; // source node is reachable to itself duh... right?
    for(size_t i = 0; i < adjList->at(src).size(); i++) {
        Edge edge = adjList->at(src).at(i);
        distances[edge.dest] = edge.weight;
    }
    hasVisited[src] = true;
    int currentNode = findShortestUnvisited(hasVisited, distances);
    

    // analyze the rest of the nodes, which is basically the same as above
    // This is about O(V*E) currently. If you have time and energy, it may be worth
    // using a min-queue instead of scanning array to find next node.
    while(currentNode != -1) {
        for(size_t i = 0; i < adjList->at(currentNode).size(); i++) {
            Edge edge = adjList->at(currentNode).at(i);

            int newPathWeight = edge.weight + distances[currentNode];
            if(distances[edge.dest] == -1) { // was currently unreachable
                distances[edge.dest] = newPathWeight;
            }
            else { // there already exists path from src to edge.dest; compare weights
                if(distances[edge.dest] > newPathWeight) {
                    distances[edge.dest] = newPathWeight;
                }
            }
        }
        hasVisited[currentNode] = true;
        currentNode = findShortestUnvisited(hasVisited, distances);
    }


    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> time = stop - start;
    timeTaken = time.count();
    return true;

}

// Returns the index of the node with the smallest distance that hasn't been visited,
// or -1 if all the nodes have been visited.
int Dijkstra::findShortestUnvisited(vector<bool>& hasVisited, vector<int>& distances) {
    int indexOfSmallest = -1;
    int distanceOfSmallest = -1;

    // First, find the first unvisited node
    size_t i; // index
    for(i = 0; i < distances.size(); i++) {
        // Note: distance of -1 implies not reachable yet and not a candidate for next step in Dijkstra's
        if(hasVisited[i] == false && distances[i] != -1) { 
            indexOfSmallest = i;
            distanceOfSmallest = distances[i];
            break;
        }
    }

    // Now we can start comparing the other unvisited nodes
    // Note: distance of -1 implies not reachable yet and not a candidate for next step in Dijkstra's
    for(i = i + 1; i < distances.size(); i++) {
        if(hasVisited[i] == false && distances[i] != -1 && distances[i] < distanceOfSmallest) {
            indexOfSmallest = i;
            distanceOfSmallest = distances[i];
        }
    }


    return indexOfSmallest;
}

void Dijkstra::printDistances() {
    printf("Vertex\t\t Distance from Source\n");
    for (int i = 0; i < numVerticies; i++) {
        if(distances[i] < 0) {
            printf("%d \t\t INF\n", i);
        }
        else {
            printf("%d \t\t %d\n", i, distances[i]);
        }
    }
}