#ifndef JOHNSON_H
#define JOHNSON_H

#include "TestCase.h"

using namespace std;

class Johnson {
public: 
	vector<int> distances;
	double timeTaken;

	Johnson(TestCase &testCase);
	
	bool findShortestPathsFromSource(int src);
	void printDistances();

private:
	int numVerticies;
	vector<vector<Edge>> *adjList;

};

#endif