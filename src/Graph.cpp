#include "Graph.h"
#include <fstream>
#include <iostream>

void Graph::Load(std::string filename)
{
    std::ifstream fin(filename);
    int vertexes_amount = 0;
    int edges_amount = 0;
    fin >> vertexes_amount;
    fin >> edges_amount;
    for (int i = 0; i < vertexes_amount; i++)
    {
        vertex new_vertex;
        new_vertex.name = i;
        Graph::vertexes.push_back(new_vertex);
    }
    for (int i = 0; i < edges_amount; i++)
    {
        int in, out;
        fin >> in >> out;
        Graph::vertexes[in-1].neighbours.push_back(Graph::vertexes[out-1]);
        Graph::vertexes[out-1].neighbours.push_back(Graph::vertexes[in-1]);
    }
    std::cout << "Finished loading graph data!!\n";
}