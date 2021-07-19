#include "Johnson.h"
#include "FloydWarshall.h"
#include "BellmanFord.h"
#include "Dijkstra.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct TestCase {
	std::vector<std::vector<int>> arr;
};

int main(int argc, char * argv[])
{
	std::fstream file;
	std::string templine;
	std::vector<TestCase> AllTests;

	std::string TestFile = argv[1];
	file.open(TestFile);
	std::cout<<"File is open"<<std::endl;

	while (!file.eof())
	{
		while(std::getline(file, templine))
		{
		
		}
	}
	file.close();

	Johnson J;
	FloydWarshall F;
	BellmanFord B;
	Dijkstra D;

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
