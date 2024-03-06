#include <vector>
#include <map>
#include "Graph.h"

#define K 9
#define L 60


class GraphBuilder 
{
public:
    std::vector<point> GetPoints();
    void CountConstraints(std::map<int, std::map<int, std::vector<int>>>);
private:
    double GetEnergy();
    double GetEnergyDiff_Y(int);
    double GetEnergyDiff_X(int);
    double GetEnergySecondDiff_XX(int m);
    double GetEnergySecondDiff_XY(int m);
    double GetEnergySecondDiff_YY(int m);

    std::vector<std::vector<double>> l;
    std::vector<std::vector<double>> k;
    std::vector<point> R2points;
    std::map<int, std::map<int, std::vector<int>>> distance_data;
};