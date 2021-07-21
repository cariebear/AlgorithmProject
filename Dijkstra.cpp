#include "Dijkstra.h"

#include <iostream>

using namespace std;

Dijkstra::Dijkstra(TestCase &testCase) {
    adjList = &testCase.adjList;
    numVerticies = adjList->size();
    distances.resize(numVerticies);
}

bool Dijkstra::findShortestPathsFromSource(int src) {

    // algorithm impl here
    return true;

}

void Dijkstra::printDistances() {
    printf("\n*** Dijkstra ***");
    printf("\nVertex\t\t Distance from Source\n");
    for (int i = 0; i < numVerticies; i++) {
        printf("%d \t\t %d\n", i, distances[i]);
    }
}