/*
Author: 		Martin Stryffeler
Filename: 		nn.hpp
Date: 			3/11/2016
Description: 	Nearest neighbor header file. Approximation algorithm 
				for the travelling salesman problem
*/

#include <vector>

#ifndef NN_H
#define NN_H

//Generate a random adjacency matrix
std::vector< std::vector<int> > randAdjMatrix(int numCities);

//Get the nearest neighbor tour of an adjacency matrix
std::vector<int> nnTour(std::vector< std::vector<int> > adjacencyMatrix, int numCities);

//Calculate the cost of a tour
int getCost(std::vector< std::vector<int> > adjacencyMatrix, std::vector<int> tour);

#endif // DICE_HPP_INCLUDED