#include "Graph.h"

#include <algorithm>
#include <deque>
#include <fstream>
#include <iostream>

using distance_table = std::map<int, std::vector<int>>;

void Graph::Load(std::string filename) {
  std::ifstream fin(filename);
  int vertexes_amount = 0;
  int edges_amount = 0;
  fin >> vertexes_amount;
  fin >> edges_amount;
  for (int i = 0; i < vertexes_amount; i++) {
    vertex new_vertex;
    new_vertex.name = i;
    Graph::vertexes.push_back(new_vertex);
  }
  for (int i = 0; i < edges_amount; i++) {
    int in, out;
    fin >> in >> out;
    Graph::vertexes[in - 1].neighbours.push_back(&Graph::vertexes[out - 1]);
    Graph::vertexes[out - 1].neighbours.push_back(&Graph::vertexes[in - 1]);
  }
  std::cout << "Finished loading graph data!!\n";
}

std::vector<vertex> Graph::GetVertexes() { return Graph::vertexes; }

distance_table Graph::GetDistancesForVertex(int vertex_number) {
  distance_table result = {{0, {vertex_number}}};
  std::deque<std::pair<int, vertex*>> queue;
  queue.push_back({0, &Graph::vertexes[vertex_number]});
  std::vector<int> was = {vertex_number};
  while (queue.size() > 0) {
    for (int i = 0; i < queue[0].second->neighbours.size(); i++) {
      if (std::find(was.begin(), was.end(),
                    queue[0].second->neighbours[i]->name) == was.end()) {
        queue.push_back({queue[0].first + 1, queue[0].second->neighbours[i]});
        result[queue[0].first + 1].push_back(
            queue[0].second->neighbours[i]->name);
        was.push_back(queue[0].second->neighbours[i]->name);
      }
    }
    queue.pop_front();
  }
  return result;
}

lenmap Graph::GetDistancesTable() {
  lenmap result;
  for (int i = 0; i < Graph::vertexes.size(); i++) {
    result[i] = Graph::GetDistancesForVertex(i);
  }
  return result;
}
