#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "TestCase.h"

using namespace std;

class Dijkstra {
public: 
	vector<int> distances;
	double timeTaken;

	Dijkstra(TestCase &testCase);
	
	bool findShortestPathsFromSource(int src);
	void printDistances();
	
private:
	int numVerticies;
	vector<vector<Edge>> *adjList;

};

#endif