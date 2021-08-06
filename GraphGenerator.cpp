// graph generator

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <algorithm>

struct Info {
	int dest;
	int weight;
};


void RandomGraph(int vertices, int weight, bool sparse, bool direction)
{
	std::vector<std::vector<Info>> List;
	List.resize(vertices);
	srand(time(NULL));

	for (int i = 0; i < vertices; i++)
	{
		int numedges;
		if (sparse)
		{
			numedges = (std::rand() % 3) + 1;
		}
		else 
		{
			numedges = (std::rand() % vertices) + 1;
		}

		int tempEdge = 0;
		while (tempEdge < numedges - 1)
		{
			std::vector<int> v;
			for (int j = 0; j < numedges; j++)
			{
				int edge = (std::rand() % vertices);
				std::vector<int>::iterator it = std::find(v.begin(), v.end(), edge);
				if (edge != i &&  it == v.end())
				{//if it is not equal to self and not in vector
					int weight = (std::rand()%10) + weight; //random number from -1 to 9
					v.push_back(edge);
					List[i].push_back({edge, weight});
					//std::cout<<"EHe"<<tempEdge<<" "<<numedges<<std::endl;
					tempEdge++;
				}
				
			}
		}
	}

	std::string temp;
	if (weight < 0 && sparse && direction)
	{
		temp = "negSparseFalse/" + std::to_string(vertices) + ".txt";
	}
	else if (weight < 0 && !sparse && direction)
	{
		temp = "negNotSparseFalse/" + std::to_string(vertices) + ".txt";
	}
	else if (weight < 0 && sparse && !direction)
	{
		temp = "negSparseTrue/" + std::to_string(vertices) + ".txt";
	}
	else if (weight < 0 && !sparse && !direction)
	{
		temp = "negNotSparseTrue/" + std::to_string(vertices) + ".txt";
	}
	else if (weight == 0 && sparse && direction)
	{
		temp = "posSparseFalse/" + std::to_string(vertices) + ".txt";
	}
	else if (weight == 0 && !sparse && direction)
	{
		temp = "posNotSparseFalse/" + std::to_string(vertices) + ".txt";
	}
	else if (weight == 0 && sparse && !direction)
	{
		temp = "posSparseTrue/" + std::to_string(vertices) + ".txt";
	}
	else if (weight == 0 && !sparse && !direction)
	{
		temp = "posNotSparseTrue/" + std::to_string(vertices) + ".txt";
	}
	std::cout<<temp<<std::endl;
	std::ofstream file(temp);
	file << vertices << std::endl;
	
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
			file << i << " " << List.at(i).at(j).dest << " " << List.at(i).at(j).weight << std::endl;
		}
	}

	file.close();
}

int main()
{

	for (int i = 6; i < 100; i++)
	{
		RandomGraph(i, 0, true, true);
		RandomGraph(i, 0, true, false);
		RandomGraph(i, 0, false, true);
		RandomGraph(i, 0, false, false);
		RandomGraph(i, -1, true, true);
		RandomGraph(i, -1, true, false);
		RandomGraph(i, -1, false, true);
		RandomGraph(i, -1, false, false);
		//std::cout<<"Done with: "<<i<<std::endl;
	}
	std::cout<<"Done!"<<std::endl;
	return 0;
}