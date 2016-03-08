/*
Author: 		Martin Stryffeler
Filename: 		main.cpp
Date: 			3/11/2016
Description: 	Nearest neighbor example program.
*/

#include "nn.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand( time(0) );		//Be sure to seed if using the random matrix generator
	int numCities = 5;

	//Generate a random adjacency matrix
	std::vector< std::vector<int> > adjacencyMatrix = randAdjMatrix(numCities);

	//Output matrix
	for(int i = 0; i < numCities; i++)
	{
		for(int j = 0; j < numCities; j++)
		{
			std::cout << adjacencyMatrix[i][j] << '\t';
		}
		std::cout << std::endl;
	}

	//Get nearest neighbor tour
	std::vector<int> tour = nnTour(adjacencyMatrix, numCities);
	
	//Output tour
	for(int i = 0; i <= numCities; i++)
	{
		std::cout << tour[i] << '\t';
	}
	std::cout << std::endl;

	//Get and output cost
	int cost = getCost(adjacencyMatrix, tour);
	std::cout << "Total cost: " << cost << std::endl;

	return 0;
}