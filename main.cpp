#include "Johnson.h"
#include "FloydWarshall.h"
#include "BellmanFord.h"
#include "Dijkstra.h"
#include "TestCase.h"

#include <string>
#include <vector>

using namespace std;

int main(int argc, char * argv[]) {
	vector<string> arguments(argv, argv + argc);
	vector<TestCase> allTests;
	for (size_t i = 1; i < arguments.size(); i++) {
		string& fileName = arguments.at(i);
	
		// build test case graph
		TestCase testCase(fileName);
		testCase.printList();

		// test algorithms
		Dijkstra D(testCase);
		printf("\n*** Dijkstra ***\n");
		if (D.findShortestPathsFromSource(0)) {
			D.printDistances();
		} else {
			printf("Could not find shortest distances for Dijkstra.\n");
		};
		printf("Time taken: %f ms\n", D.timeTaken);

		BellmanFord B(testCase);
		printf("\n*** BellmanFord ***\n");
		if (B.findShortestPathsFromSource(0)) {
			B.printDistances();
		} else {
			printf("Could not find shortest distances for BellmanFord.\n");
		};
		printf("Time taken: %f ms\n", B.timeTaken);

		Johnson J(testCase);
		printf("\n*** Johnson ***\n");
		if (J.findShortestPaths()) {
			J.printDistances();
		} else {
			printf("Could not find shortest distances for Johnson.\n");
		};
		printf("Time taken: %f ms\n", J.timeTaken);

		FloydWarshall F(testCase);
		printf("\n*** Floyd Warshall ***\n");
		if (F.findShortestPaths()) {
			F.printDistances();
		} else {
			printf("Could not find shortest distances for FloydWarshall.\n");
		};
		printf("Time taken: %f ms\n", F.timeTaken);
	}

	return 0;
}

/*
Test cases:
	Single source shortest path
	Single destination shortest path
	All pairs shortest path 

	Sparse graph
	Dense graph
*/
