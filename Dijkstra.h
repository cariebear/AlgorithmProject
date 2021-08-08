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
	int findShortestUnvisited(vector<bool>& hasVisited, vector<int> & distances);
	const int INF = std::numeric_limits<int>::max();
};

#endif