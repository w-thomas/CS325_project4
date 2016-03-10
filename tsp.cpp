#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <sstream>

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
  for (int a = 0; a < numPoints; a++){
    for (int b = 0; b < numPoints; b++){
      std::cout << pointList.size() << '\n';
      std::cout << pointList[a].number << '\n';
      matrix[a][b] = round(sqrt((pointList[a].x - pointList[b].x)^2 + (pointList[a].y - pointList[b].y)^2));
    }
  }
  std::cout << "Here3\n";
  
}

int main(int argc, char** argv){
  std::vector< std::vector<int> > matrix;
  get_input(argv[1], matrix);
  return 0;
}