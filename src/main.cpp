#include <ctime>
#include <iostream>

#include "GraphDrawer.h"

using namespace std;

int main() {
  unsigned int start_time = clock();
  Graph* mygraph = new Graph();
  mygraph->Load("infile.txt");
  std::map<int, std::map<int, std::vector<int>>> distance_data =
      mygraph->GetDistancesTable();
  GraphBuilder* mygraphbuilder = new GraphBuilder();
  mygraphbuilder->CountConstraints(distance_data);
  std::vector<point> points = mygraphbuilder->GetPoints();
  /*
  for(int i = 0; i < points.size(); i ++)
  {
      std::cout << points[i].x << " " << points[i].y << '\n';
  }
  */
  GraphDrawer* mydrawer = new GraphDrawer();
  mydrawer->DrawGraph(points, mygraph->GetVertexes());
  unsigned int end_time = clock();
  std::cout << "Time taken: " << (end_time - start_time) / 1000.0 << '\n';
  return 0;
}