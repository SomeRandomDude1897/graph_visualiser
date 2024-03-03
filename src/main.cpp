#include <iostream>
#include "GraphBuilder.h"
using namespace std;

int main()
{
    Graph* mygraph = new Graph();
    mygraph -> Load("infile.txt");
    std::map<int, std::map<int, std::vector<int>>> distance_data = mygraph -> GetDistancesTable();
    GraphBuilder* mygraphbuilder = new GraphBuilder();
    mygraphbuilder -> CountConstraints(distance_data);
    std::vector<point> points = mygraphbuilder -> GetPoints();
    double middle_x = 0;
    double middle_y = 0;

    for (int i = 0; i < points.size(); i ++)
    {
        middle_x += (int) (points[i].x);
        middle_y += (int) (points[i].y);
    }

    middle_x /= points.size();
    middle_y /= points.size();

    for (int i = 0; i < points.size(); i ++)
    {
        std::cout << points[i].name << " : " << (int) (points[i].x -  middle_x ) << " " << (int) (points[i].y - middle_y) << '\n';
    }
    return 0;
}