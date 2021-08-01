#ifndef JOHNSON_H
#define JOHNSON_H

#include "TestCase.h"

using namespace std;

class Johnson {
public: 
	vector<int> distances;
	vector<vector<int>> distPositive;
	double timeTaken;

	Johnson(TestCase &testCase);
	
	bool findShortestPathsFromSource(int src);
	void printDistances();
	int getVert();

private:
	int numVerticies;
	vector<vector<Edge>> *adjList;
	const int INF = std::numeric_limits<int>::max();
};

#endif