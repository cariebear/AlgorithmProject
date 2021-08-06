// graph generator

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>

struct Info {
	int dest;
	int weight;
};


void RandomGraph(int vertices)
{
	std::vector<std::vector<Info>> List;
	List.resize(vertices);
	srand(time(NULL));
	for (int i = 0; i < vertices; i++)
	{
		int numedges = (std::rand() % vertices);
		if (numedges > 0)
		{
			for (int j = 0; j < numedges; j++)
			{
				int edge = (std::rand() % vertices);
				int weight = (std::rand()%10) + (-1); //random number from -1 to 9
				List[i].push_back({edge, weight});
			}
		}
		

	}

	std::string temp = "Tests/" + std::to_string(vertices) + ".txt";
	std::ofstream file(temp);
	file << vertices << std::endl;
	file << "false" << std::endl;

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
		RandomGraph(i);
		std::cout<<"Done with: "<<i<<std::endl;
	}
	std::cout<<"Done!"<<std::endl;
	return 0;
}