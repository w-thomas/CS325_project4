#include <vector>


//Pairwise optimization of completed tour
std::vector<int> two_opt(std::vector<int> nnTour, std::vector< std::vector<int> > adjacencyMatrix, int numCities);

std::vector<int> two_optSwap(std::vector<int> nnTour, int swapFront, int swapEnd, int numCities);
