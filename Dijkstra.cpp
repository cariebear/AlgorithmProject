#include "Dijkstra.h"

#include <iostream>
#include <chrono>

using namespace std;

Dijkstra::Dijkstra(TestCase &testCase) {
    adjList = &testCase.adjList;
    numVerticies = adjList->size();
    distances.resize(numVerticies);
}

bool Dijkstra::findShortestPathsFromSource(int src) {
    auto start = chrono::high_resolution_clock::now();
    
    // Algorithim Implementation Here

    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> time = stop - start;
    timeTaken = time.count();
    return true;

}

void Dijkstra::printDistances() {
    printf("\n*** Dijkstra ***");
    printf("\nVertex\t\t Distance from Source\n");
    for (int i = 0; i < numVerticies; i++) {
        printf("%d \t\t %d\n", i, distances[i]);
    }
}