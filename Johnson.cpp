#include "Johnson.h"

#include <iostream>

using namespace std;

Johnson::Johnson(TestCase &testCase) {
    adjList = &testCase.adjList;
    numVerticies = adjList->size();
    distances.resize(numVerticies);
}

bool Johnson::findShortestPathsFromSource(int src) {
    // TODO
    return true;
}

void Johnson::printDistances() {
    printf("\n*** Johnson ***");
    printf("\nVertex\t\t Distance from Source\n");
    for (int i = 0; i < numVerticies; i++) {
        printf("%d \t\t %d\n", i, distances[i]);
    }
}