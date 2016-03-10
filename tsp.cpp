#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>

class point{
  public:
    int number;
    int x;
    int y;
};

void get_input(char* fName, std::vector< std::vector<int> >& matrix){
  std::vector<point> pointList;
  int i, number, x, y, switcher = 1;
  std::cout << "here1\n";
  std::ifstream file;
  file.open(fName);
  while (file >> i){
    switch (switcher){
      case 1:
        number = i;
        switcher++;
        break;
      case 2:
        x = i;
        switcher++;
        break;
      case 3:
        y = i;
        switcher = 1;
        break;
      default:
        std::cout << "error in reading file\n";
    }
    point a;
    a.number = number;
    a.x = x;
    a.y = y;
    pointList.push_back(a);
  }
  file.close();
  std::cout << "here2\n";
  // Now we want to turn the list of points into an adjacency matrix.
  int numPoints = pointList.size();
  for (int a = 0; a < numPoints; a++){
    for (int b = 0; b < numPoints; b++){
      std::cout << pointList[a].x;
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