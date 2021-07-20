#include "Johnson.h"
#include "FloydWarshall.h"
#include "BellmanFord.h"
#include "Dijkstra.h"
#include "Edge.h"
#include "TestCase.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char * argv[]) {
	vector<string> arguments(argv, argv + argc);
	vector<TestCase> allTests;
	for (size_t i = 1; i < arguments.size(); i++) {
		string& testFile = arguments.at(i);
		ifstream infile(testFile);

		int src, dest, weight;
		vector<Edge> edges;
	
		// assuming first line is the number of verticies in the graph
		string firstLine;
		getline(infile, firstLine);
		// read rest of lines to create edges
		while (infile >> src >> dest >> weight) {
			edges.push_back({src, dest, weight});
		}
		TestCase testCase(edges, stoi(firstLine));
		cout << "Undirected Graph from file: " << testFile << "\n";
		testCase.printList();
		printf("\n");

		Johnson J(testCase);
		FloydWarshall F(testCase);
		BellmanFord B(testCase);
		Dijkstra D(testCase);
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
