#include <map>
#include <string>
#include <vector>

using lenmap = std::map<int, std::map<int, std::vector<int>>>;

struct vertex {
  int name = -1;
  std::vector<vertex*> neighbours = {};
};
struct point {
  int name;
  double x, y;
};

class Graph {
 private:
  std::vector<vertex> vertexes;
  std::map<int, std::vector<int>> GetDistancesForVertex(int);

 public:
  void Load(std::string);
  std::vector<vertex> GetVertexes();
  lenmap GetDistancesTable();  // если что я готов это переделать, просто не
                               // придумал ничего лучше в моменте
};