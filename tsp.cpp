#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <sstream>
#include "tsp.hpp"

class point{
  public:
    int number;
    int x;
    int y;
};

void get_input(char* fName, std::vector< std::vector<int> >& matrix){
  std::vector<point> pointList;
  std::ifstream file;
  std::string line;
  file.open(fName);
  while (std::getline(file, line)){
    std::istringstream iss(line);
    point a;
    iss >> a.number;
    iss >> a.x;
    iss >> a.y;
    pointList.push_back(a);
  }
  file.close();

  // Now we want to turn the list of points into an adjacency matrix.
  int numPoints = pointList.size();
  matrix.resize(numPoints, std::vector<int>(numPoints, -1));

  for (int a = 0; a < numPoints; a++){
    for (int b = 0; b < numPoints; b++){
      matrix[a][b] = round(sqrt((pointList[a].x - pointList[b].x)*(pointList[a].x - pointList[b].x) + (pointList[a].y - pointList[b].y)*(pointList[a].y - pointList[b].y)));
      //std::cout << pointList[a].number << " " << pointList[b].number << " " << matrix[a][b] << std::endl;
    }
  }
}
