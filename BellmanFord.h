#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include "TestCase.h"

using namespace std;

class BellmanFord {
public: 
	vector<int> distances;
	BellmanFord(TestCase &testCase);
	bool findShortestPathsFromSource(int src);
	void printDistances();
	double timeTaken;

private:
	int numVerticies;
	vector<vector<Edge>> *adjList;
};

#endif