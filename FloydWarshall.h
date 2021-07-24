#ifndef FLOYDDWARSHALL_H
#define FLOYDDWARSHALL_H

#include "TestCase.h"
#include <limits>

using namespace std;

class FloydWarshall {
public: 
	vector<vector<int>> distMatrix;
	double timeTaken;

	FloydWarshall(TestCase &testCase);
	
	bool findShortestPaths();
	void printDistances();
	
private:
	int numVerticies;
	vector<vector<Edge>> *adjList;
	const int INF = std::numeric_limits<int>::max();
};

#endif