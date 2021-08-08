// graph generator

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <algorithm>

struct Info {
	int _dest;
	int _weights;
};

void RandomGraph(int vertices, int weight, bool sparse, bool direction)
{
	std::vector<std::vector<Info>> List;
	List.resize(vertices);
	srand(time(NULL));
	int Edges = 0;

	for (int i = 0; i < vertices; i++)
	{
		int numedges = 0;
		int tempEdge = 0;
		if (sparse)
		{
			numedges = (std::rand() % 3);
		}
		else if (!sparse)
		{
			numedges = (std::rand() % vertices) - 1;
		}
		numedges++;
		std::vector<int> v;
		while (tempEdge < numedges)
		{
			int edge = (std::rand() % vertices);
			//std::cout << edge << std::endl;
			std::vector<int>::iterator it = std::find(v.begin(), v.end(), edge);
			int _weights = (std::rand()%19) + weight; //random number from -1 to 9
			if (edge != i &&  it == v.end())
			{//if it is not equal to self and not in vector
				v.push_back(edge);
				List[i].push_back({edge, _weights});
				tempEdge++;
				Edges++;
			}
		}
	}

	std::string temp;
	if (weight < 0 && sparse && direction)
	{
		temp = "nSparseFalse/" + std::to_string(vertices) + ".txt";
	}
	else if (weight < 0 && !sparse && direction)
	{
		temp = "nNotSparseFalse/" + std::to_string(vertices) + ".txt";
	}
	else if (weight < 0 && sparse && !direction)
	{
		temp = "nSparseTrue/" + std::to_string(vertices) + ".txt";
	}
	else if (weight < 0 && !sparse && !direction)
	{
		temp = "nNotSparseTrue/" + std::to_string(vertices) + ".txt";
	}
	else if (weight == 0 && sparse && direction)
	{
		temp = "pSparseFalse/" + std::to_string(vertices) + ".txt";
	}
	else if (weight == 0 && !sparse && direction)
	{
		temp = "pNotSparseFalse/" + std::to_string(vertices) + ".txt";
	}
	else if (weight == 0 && sparse && !direction)
	{
		temp = "pSparseTrue/" + std::to_string(vertices) + ".txt";
	}
	else if (weight == 0 && !sparse && !direction)
	{
		temp = "pNotSparseTrue/" + std::to_string(vertices) + ".txt";
	}

	std::ofstream file(temp);
	file << vertices << std::endl;
	file << Edges << std::endl;
	
	if (direction)
	{
		file << "true" <<std::endl;
	}
	else 
	{
		file << "false" << std::endl;
	}

	for (int i = 0; i < List.size(); i++)
	{
		for (int j = 0; j < List.at(i).size(); j++)
		{
			file << i << " " << List.at(i).at(j)._dest << " " << List.at(i).at(j)._weights << std::endl;
		}
	}
	file.flush();
	file.close();
}

int main()
{

	for (int i = 5; i < 100; i++)
	{
		RandomGraph(i, 0, true, true);
		RandomGraph(i, 0, true, false);
		RandomGraph(i, 0, false, true);
		RandomGraph(i, 0, false, false);
		RandomGraph(i, -9, true, true);
		RandomGraph(i, -9, true, false);
		RandomGraph(i, -9, false, true);
		RandomGraph(i, -9, false, false);
		std::cout<<"Done with: "<<i<<std::endl;
	}
	std::cout<<"Done!"<<std::endl;
	return 0;
}