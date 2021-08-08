#include "BellmanFord.h"

#include <iostream>
#include <chrono>

using namespace std;

BellmanFord::BellmanFord(TestCase &testCase) {
    adjList = &testCase.adjList;
    numVerticies = adjList->size();
    distances.resize(numVerticies);
    timeTaken = 0.0;
}

bool BellmanFord::findShortestPathsFromSource(int src) {
    auto start = chrono::high_resolution_clock::now();

    // initalize distancesances
    for (int i = 0; i < numVerticies; i++) {
        distances[i] = __INT_MAX__;
    }
    distances[src] = 0;

    // iterate to produce distances
    for (int i = 0; i < numVerticies - 1; i++) {
        for (size_t i = 0; i < adjList->size(); i++) {
            for (size_t j = 0; j < adjList->at(i).size(); j++) {
                int dest = adjList->at(i).at(j).dest;
                int weight = adjList->at(i).at(j).weight;
                if (distances[i] != __INT_MAX__ && distances[i] + weight < distances[dest]) {
                    distances[dest] = distances[i] + weight;
                }
            }
        }
    }

    // check for negative cycles
    for (size_t i = 0; i < adjList->size(); i++) {
        for (size_t j = 0; j < adjList->at(i).size(); j++) {
            int dest = adjList->at(i).at(j).dest;
            int weight = adjList->at(i).at(j).weight;
            if (distances[i] != __INT_MAX__ && distances[i] + weight < distances[dest]) {
                auto stop = chrono::high_resolution_clock::now();
                chrono::duration<double, std::milli> time = stop - start;
                timeTaken = time.count();
                return false;
            }
        }
    }

    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> time = stop - start;
    timeTaken = time.count();
    return true;
}

void BellmanFord::printDistances() {
    printf("Vertex\t\t Distance from Source\n");
    for (int i = 0; i < numVerticies; i++) {
        printf("%d \t\t %d\n", i, distances[i]);
    }
}