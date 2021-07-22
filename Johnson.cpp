#include "Johnson.h"

#include <iostream>
#include <chrono>

using namespace std;

Johnson::Johnson(TestCase &testCase) {
    adjList = &testCase.adjList;
    numVerticies = adjList->size();
    distances.resize(numVerticies);
}

bool Johnson::findShortestPathsFromSource(int src) {
    auto start = chrono::high_resolution_clock::now();
    
    // Algorithim Implementation Here

    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> time = stop - start;
    timeTaken = time.count();
    return true;
}

void Johnson::printDistances() {
    printf("\n*** Johnson ***");
    printf("\nVertex\t\t Distance from Source\n");
    for (int i = 0; i < numVerticies; i++) {
        printf("%d \t\t %d\n", i, distances[i]);
    }
}