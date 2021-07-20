#ifndef TESTCASE_H
#define TESTCASE_H

#include "Edge.h"
#include "Node.h"

#include <vector>

using namespace std;

class TestCase {
    public:
        vector<vector<Node>> adjList;
        TestCase(vector<Edge> &edges, int n);
        void printList();
    private:
};

#endif