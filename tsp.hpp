#include <vector>

#ifndef TSP_H
#define TSP_H

//Takes input from a given filename and returns a 2D vector adjacency matrix
void get_input(char* fName, std::vector< std::vector<int> >& matrix);

#endif // TSP_HPP_INCLUDED