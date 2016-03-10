/*
Author: 		Martin Stryffeler
Filename: 		nn.cpp
Date: 			3/11/2016
Description: 	Nearest neighbor implementation file. Approximation algorithm 
				for the travelling salesman problem

Sources:
Followed logic from nearest neighbor algorithm wikipedia page:
https://en.wikipedia.org/wiki/Nearest_neighbour_algorithm
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <algorithm>
#include "nn.hpp"

/*
	Function randAdjMatrix(int numCities)
	Random adjacency matrix generator
	Takes the number of cities as an integer
	Returns an adjacency matrix in the form of a 2D vector
*/
std::vector< std::vector<int> > randAdjMatrix(int numCities)
{
	std::vector< std::vector<int> > adjacencyMatrix;
	adjacencyMatrix.resize(numCities, std::vector<int>(numCities, 0));
	int randNum;

	for(int i = 0; i < numCities; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			randNum = std::rand() % 200 + 1;
			if(i == j)
				randNum = -1;
			adjacencyMatrix[i][j] = randNum;
			adjacencyMatrix[j][i] = randNum;
		}
	}

	return adjacencyMatrix;
}

/*
	Function nnTour(std::vector< std::vector<int> > adjacencyMatrix, int numCities)
	Nearest neighbor algorithm for the travelling salesman problem
	Takes an adjacency matrix as a 2D vector and the number of cities as an integer
	Returns a tour of all cities, ending at the starting city
*/
std::vector<int> nnTour(std::vector< std::vector<int> > adjacencyMatrix, int numCities)
{
	int currentCity, nextCity;
	int minDistance;
	std::vector<int> tour;
	tour.resize(numCities + 1, -1);
		
	currentCity = 0;

	for(int j = 0; j < numCities; j++)
	{
		minDistance = std::numeric_limits<int>::max();
		tour[j] = currentCity;
		for(int i = 0; i < numCities; i++)
		{
			if(i != currentCity && adjacencyMatrix[currentCity][i] < minDistance && !(std::find(tour.begin(), tour.end(), i) != tour.end()))
			{
				minDistance = adjacencyMatrix[currentCity][i];
				nextCity = i;
			}
		}
		currentCity = nextCity;
	}

	tour[numCities] = 0;	
	return tour;
}
/*
	Function getCost(std::vector< std::vector<int> > adjacencyMatrix, std::vector<int> tour)
	Calculates the cost of a given tour
	Takes an adjacency matrix as a 2D vector and a tour as a vector
	Returns the total cost of the tour as an integer
*/
int getCost(std::vector< std::vector<int> > adjacencyMatrix, std::vector<int> tour)
{
	int cost, totalCost;
	int tourLength = tour.size();
	int currentCity, nextCity;

	totalCost = 0;

	for(int i = 0; i < tourLength - 1; i++)
	{
		currentCity = tour[i];
		nextCity = tour[i+1];
		cost = adjacencyMatrix[currentCity][nextCity];
		totalCost += cost;
	}

	return totalCost;
}