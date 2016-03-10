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

void get_input(std::string fName, std::vector< std::vector<int> >& matrix){
  std::vector<point> pointList;
  int i, number, x, y, switcher = 1;
  std::ifstream file(fName);
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
  
  // Now we want to turn the list of points into an adjacency matrix.
  int numPoints = pointList.size();
  for (int a = 0; a < numPoints; a++){
    for (int b = 0; b < numPoints; b++){
      matrix[a][b] = round(sqrt((a.x - b.x)^2 + (a.y - b.y)^2));
    }
  }
  
}

int main(int argc, std::string * argv){
  std::vector< std::vector<int> > matrix;
  get_input(argv[1], &matrix);
  return 0;
}