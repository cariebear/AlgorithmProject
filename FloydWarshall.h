#ifndef FLOYDDWARSHALL_H
#define FLOYDDWARSHALL_H

#include "TestCase.h"

using namespace std;

class FloydWarshall {
public: 
	vector<int> distances;
	double timeTaken;

	FloydWarshall(TestCase &testCase);
	
	bool findShortestPaths();
	void printDistances();
	
private:
	int numVerticies;
	vector<vector<Edge>> *adjList;

};

#endif