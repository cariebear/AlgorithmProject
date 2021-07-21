#include "FloydWarshall.h"

#include <iostream>

using namespace std;

FloydWarshall::FloydWarshall(TestCase &testCase) {
    adjList = &testCase.adjList;
    numVerticies = adjList->size();
    distances.resize(numVerticies);
}

bool FloydWarshall::findShortestPaths() {
    // TODO
    return true;
}

void FloydWarshall::printDistances() {
    printf("\n*** FloydWarshall ***");
    // TODO
}