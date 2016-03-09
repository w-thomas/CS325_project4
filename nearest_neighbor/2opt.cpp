#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "2opt.hpp"
#include "nn.hpp"

std::vector<int> two_opt(std::vector<int> nnTour, std::vector< std::vector<int> > adjacencyMatrix, int numCities)
{
	//get tour size
	int size = nnTour.size();

	//repeat until no improvement is made
	int improve = 0;

	std::vector<int> finalTour = nnTour;

	while (improve < 20)
	{	
		//Iterate through route and swap edges
		int best_dist = getCost(adjacencyMatrix, nnTour);
		for (int i = 0; i < size - 1; i++)
		{
			for (int k = i+1; k < size; k++)
			{
				std::vector<int> newTour = two_optSwap(nnTour, i, k, numCities);
				int new_dist = getCost(adjacencyMatrix, newTour);

				//Improvement found, start over
				if(new_dist < best_dist)
				{
					improve = 0;
					finalTour = newTour;
					best_dist = new_dist;
				}
			}
		}

		improve++;
	}

	return finalTour;
}

//Based off 2-opt explanation on wikipedia:
/*     1. take route[1] to route[i-1] and add them in order to new_route
       2. take route[i] to route[k] and add them in reverse order to new_route
       3. take route[k+1] to end and add them in order to new_route
*/
std::vector<int> two_optSwap(std::vector<int> nnTour, int swapFront, int swapEnd, int numCities)
{
	int size = numCities;
	std::vector<int> newTour(size);

	for (int i = 0; i < swapFront - 1; i++)
	{
		newTour[i] = nnTour[i];
	}

	int dec = 0;
	for (int i = swapFront; i < swapEnd; i++)
	{
		newTour[i] = nnTour[swapEnd - dec];
	}

	for (int i = swapEnd + 1; i < size; i++)
	{
		newTour[i] = nnTour[i];
	}

	return newTour;
}