#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "TestCase.h"

using namespace std;

class Dijkstra {
public: 
	vector<int> distances;
	Dijkstra(TestCase &testCase);
	bool findShortestPathsFromSource(int src);
	void printDistances();
	double timeTaken;
	
private:
	int numVerticies;
	vector<vector<Edge>> *adjList;

};

#endif