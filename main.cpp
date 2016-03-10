/*
Author: 		Martin Stryffeler
Filename: 		main.cpp
Date: 			3/11/2016
Description: 	Nearest neighbor example program.
*/

#include "nn.hpp"
#include "2opt.hpp"
#include "tsp.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		std::cout << "Usage: tsp filename" << std::endl;
		return 0;
	}

	//Get input
	std::vector< std::vector<int> > adjacencyMatrix;
  	get_input(argv[1], adjacencyMatrix);
  	int numCities = adjacencyMatrix.size();


  clock_t startTime, endTime;
  startTime = clock();
	//Get nearest neighbor tour
	std::vector<int> tour = nnTour(adjacencyMatrix, numCities);

	
	std::ofstream file;
	std::string fName = argv[1];
	fName += ".tour";
	file.open(fName);
	
	//Get and output cost
	int cost = getCost(adjacencyMatrix, tour);
	std::cout << "Total cost: " << cost << std::endl;
	
	file << cost << '\n';
	
	//Output tour
	std::cout << "Nearest Neighbor Tour" << std::endl;
	for(int i = 0; i <= numCities-1; i++)
	{
		std::cout << tour[i] << '\t';
		file << tour[i] << '\n';
	}
	std::cout << std::endl;

  file.close();
	endTime = clock();
	endTime -= startTime;

	//Get 2opt tour
	std::vector<int> two_optTour = two_opt(tour, adjacencyMatrix, numCities, endTime);

	//Output tour
	std::cout << "After Pairwise Comparison" << std::endl;
	for(int i = 0; i <= numCities; i++)
	{
		std::cout << two_optTour[i] << '\t';
	}
	std::cout << std::endl;

	//Get and output cost
	cost = getCost(adjacencyMatrix, two_optTour);
	std::cout << "Total cost: " << cost << std::endl;

	return 0;
}