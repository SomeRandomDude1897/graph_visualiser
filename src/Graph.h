#include <vector>
#include <string>
#include <map>

struct vertex
{
    int name = -1;
    std::vector<vertex*> neighbours = {};
};

class Graph
{
    private:
        std::vector<vertex> vertexes;
        std::map<int, std::vector<int>> GetDistancesForVertex(int);
    public:
        void Load(std::string);
        std::map<int, std::map<int, std::vector<int>>> GetDistancesTable(); // если что я готов это переделать, просто не придумал ничего лучше в моменте
};