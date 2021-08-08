#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include "TestCase.h"

using namespace std;

class BellmanFord {
public: 
	vector<int> distances;
	double timeTaken;

	BellmanFord(TestCase &testCase);
	
	bool findShortestPathsFromSource(int src);
	void printDistances();

private:
	int numVerticies;
	vector<vector<Edge>> *adjList;
	const int INF = std::numeric_limits<int>::max();
};

#endif