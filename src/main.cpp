#include <iostream>
#include "GraphDrawer.h"
using namespace std;

int main()
{
    Graph* mygraph = new Graph();
    mygraph -> Load("infile.txt");
    std::map<int, std::map<int, std::vector<int>>> distance_data = mygraph -> GetDistancesTable();
    GraphBuilder* mygraphbuilder = new GraphBuilder();
    mygraphbuilder -> CountConstraints(distance_data);
    std::vector<point> points = mygraphbuilder -> GetPoints();
    /*
    for(int i = 0; i < points.size(); i ++)
    {
        std::cout << points[i].x << " " << points[i].y << '\n';
    }
    */
    GraphDrawer* mydrawer = new GraphDrawer();
    mydrawer -> DrawGraph(points, mygraph->GetVertexes());
    return 0;
}