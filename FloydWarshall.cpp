#include "FloydWarshall.h"

#include <iostream>
#include <chrono>

using namespace std;

FloydWarshall::FloydWarshall(TestCase &testCase) {
    adjList = &testCase.adjList;
    numVerticies = adjList->size();
    distances.resize(numVerticies);
}

bool FloydWarshall::findShortestPaths() {
    auto start = chrono::high_resolution_clock::now();
    
    // Algorithim Implementation Here

    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> time = stop - start;
    timeTaken = time.count();
    return true;
}

void FloydWarshall::printDistances() {
    printf("\n*** FloydWarshall ***");
    printf("\n");
    // TODO
}