#include "FloydWarshall.h"

#include <iostream>
#include <chrono>

using namespace std;

FloydWarshall::FloydWarshall(TestCase &testCase) {
    adjList = &testCase.adjList;
    numVerticies = adjList->size();
    distMatrix = vector<vector<int>>(adjList->size(), vector<int>(adjList->size(), INF));
}

bool FloydWarshall::findShortestPaths() {
    auto start = chrono::high_resolution_clock::now();

    // Fill initial array with distances from edges
    for(size_t i = 0; i < adjList->size(); i++) {
        for(Edge edge: adjList->at(i)) {
            distMatrix.at(i).at(edge.dest) = edge.weight;
        }
    }

    // Fill initial diagonals with 0
    for(size_t i = 0; i < adjList->size(); i++) {
        distMatrix.at(i).at(i) = 0;
    }

    // Core of algorithm
    for(size_t k = 0; k < adjList->size(); k++) {
        for(size_t i = 0; i < distMatrix.size(); i++) {
            for(size_t j = 0; j < distMatrix.size(); j++) {
                if(i != j) {
                    if(distMatrix.at(i).at(k) != INF && distMatrix.at(k).at(j) != INF
                    && distMatrix.at(i).at(j) > distMatrix.at(i).at(k) + distMatrix.at(k).at(j)) {
                        distMatrix.at(i).at(j) = distMatrix.at(i).at(k) + distMatrix.at(k).at(j);
                    }
                }
                else { // is diagonal; check for negative cycles, otherwise 0 is fine.
                    if(distMatrix.at(i).at(k) != INF && distMatrix.at(k).at(j) != INF
                    && distMatrix.at(i).at(k) + distMatrix.at(k).at(j) < 0) {

                        // Negative cycle detected. Technically, the algorithm can continue
                        // with negative cycle. However, the distances could underflow and 
                        // while we could adopt a strategy to handle it, it'd be far easier to
                        // not allow it.
                        cout << "Negative cycle detected! Aborting." << endl;
                        auto stop = chrono::high_resolution_clock::now();
                        chrono::duration<double, std::milli> time = stop - start;
                        timeTaken = time.count();
                        return false;
                    }
                }
            }
        }
    }

    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> time = stop - start;
    timeTaken = time.count();
    return true;
}

void FloydWarshall::printDistances() {
    cout << "Distance Matrix" << endl;
    for(size_t i = 0; i < distMatrix.size(); i++) {
        cout << "\t" << i;    
    }
    cout << endl;
    for(size_t i = 0; i < distMatrix.size(); i++) {
        cout << i << "|\t";
        for(size_t j = 0; j < distMatrix.size(); j++) {
            if(distMatrix.at(i).at(j) == INF) {
                cout << "INF" << "\t";
            }
            else {
                cout << distMatrix.at(i).at(j) << "\t";
            }
        }
        cout << endl;
    }
}