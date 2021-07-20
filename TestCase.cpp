#include "TestCase.h"

#include <iostream>

using namespace std;

TestCase::TestCase(vector<Edge> edges, int n) {
    // resize the vector to hold `N` elements
    adjList.resize(n);

    // add edges to the undirected graph
    for (Edge edge: edges) {
        adjList[edge.src].push_back({edge.dest, edge.weight});
        adjList[edge.dest].push_back({edge.src, edge.weight});
    }
}

void TestCase::printList() {
    for (size_t i = 0; i < this->adjList.size(); i++) {
        cout << i << ": ";
        for (size_t j = 0; j < this->adjList.at(i).size(); j++) {
            Node node = this->adjList.at(i).at(j);
            if (j == 0) {
                cout << "(" << node.vertex << ", " << node.weight << ")";
            } else {
                cout << " -> (" << node.vertex << ", " << node.weight << ")";
            }
        }
        printf("\n");
    }
}