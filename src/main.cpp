#include <iostream>
#include "GraphBuilder.h"
using namespace std;

int main()
{
    Graph* mygraph = new Graph();
    mygraph -> Load("infile.txt");
    std::map<int, std::map<int, std::vector<int>>> distance_data = mygraph -> GetDistancesTable();
    for (int i = 0; i < distance_data.size(); i++)
    {
        std::cout << i << '\n';
        for (int j = 0; j < distance_data[i].size(); j++)
        {
            std::cout << j << ":\n";
            for (int k = 0; k < distance_data[i][j].size(); k++)
            {
                std::cout << distance_data[i][j][k] << " ";
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }
    return 0;
}