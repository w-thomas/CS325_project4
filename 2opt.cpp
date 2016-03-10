#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include "2opt.hpp"
#include "nn.hpp"

std::vector<int> two_opt(std::vector<int> nnTour, std::vector< std::vector<int> > adjacencyMatrix, int numCities, clock_t timer)
{
	//get tour size
	int size = nnTour.size();

	//repeat until no improvement is made
	bool improve = false;

	std::vector<int> finalTour = nnTour;
  	clock_t max_time = CLOCKS_PER_SEC * 178;
  	clock_t loop_time;
  	clock_t current_time;
	while (!improve && timer < max_time)
	{
		//Iterate through route and swap edges
		//Don't swap first and last indices
		int best_dist = getCost(adjacencyMatrix, finalTour);
		for (int i = 1; i < size - 2; i++)
		{
			for (int k = i+1; k < size - 1; k++)
			{
				std::vector<int> newTour = two_optSwap(finalTour, i, k, numCities);
				int new_dist = getCost(adjacencyMatrix, newTour);

				//Improvement found, start over
				if(new_dist < best_dist)
				{
					improve = false;
					finalTour = newTour;
					best_dist = new_dist;
				}

				//Check timer and return if necessary
				current_time = clock();
				loop_time = current_time - timer;
				if(loop_time > max_time)
				{
					std::cout << "time in seconds: " << (loop_time / CLOCKS_PER_SEC) << std::endl;
					return finalTour;
				}
			}
		}
		improve = true;
	}

  	std::cout << "time in seconds: " << (loop_time / CLOCKS_PER_SEC) << '\n';
	return finalTour;
}

//Based off 2-opt explanation on wikipedia:
/*     1. take route[1] to route[i-1] and add them in order to new_route
       2. take route[i] to route[k] and add them in reverse order to new_route
       3. take route[k+1] to end and add them in order to new_route
*/
std::vector<int> two_optSwap(std::vector<int> nnTour, int swapFront, int swapEnd, int numCities)
{
	int size = nnTour.size();
	std::vector<int> newTour = nnTour;

	for (int i = 0; i < swapFront - 1; i++)
	{
		newTour[i] = nnTour[i];
	}

	int dec = 0;
	for (int i = swapFront; i <= swapEnd; i++)
	{
		newTour[i] = nnTour[swapEnd - dec];
		dec++;
	}

	for (int i = swapEnd + 1; i < size; i++)
	{
		newTour[i] = nnTour[i];
	}

	return newTour;
}