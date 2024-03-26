#include "GraphBuilder.h"

#include <cmath>
#include <iostream>
#include <random>

void GraphBuilder::CountConstraints(
    std::map<int, std::map<int, std::vector<int>>> distances) {
  distance_data = distances;

  for (int i = 0; i < distance_data.size(); i++) {
    l.push_back({});
    k.push_back({});
    for (int j = 0; j < distance_data.size(); j++) {
      l[i].push_back(0);
      k[i].push_back(0);
    }
  }

  for (int i = 0; i < distance_data.size(); i++) {
    for (int j = 1; j < distance_data[i].size(); j++) {
      for (int o = 0; o < distance_data[i][j].size(); o++) {
        l[i][distance_data[i][j][o]] = j * L;
        k[i][distance_data[i][j][o]] = K / (j * j);
      }
    }
  }
  std::mt19937 generator(time(nullptr));
  std::uniform_real_distribution<> dist(0, 2 * distance_data.size() * L);

  for (int i = 0; i < distance_data.size(); i++) {
    point new_point;
    new_point.x = dist(generator);
    new_point.y = dist(generator);
    new_point.name = i;
    R2points.push_back(new_point);
  }
}

double GraphBuilder::GetEnergyDiff_X(int m) {
  double Energy = 0;
  for (int i = 0; i < R2points.size(); i++) {
    if (i != m) {
      Energy += k[m][i] * ((R2points[m].x - R2points[i].x) -
                           (l[m][i] * (R2points[m].x - R2points[i].x)) /
                               pow(pow((R2points[m].x - R2points[i].x), 2) +
                                       pow((R2points[m].y - R2points[i].y), 2),
                                   0.5));
    }
  }
  return Energy;
}

double GraphBuilder::GetEnergyDiff_Y(int m) {
  double Energy = 0;
  for (int i = 0; i < R2points.size(); i++) {
    if (i != m) {
      Energy += k[m][i] * ((R2points[m].y - R2points[i].y) -
                           (l[m][i] * (R2points[m].y - R2points[i].y)) /
                               pow(pow((R2points[m].x - R2points[i].x), 2) +
                                       pow((R2points[m].y - R2points[i].y), 2),
                                   0.5));
    }
  }
  return Energy;
}

double GraphBuilder::GetEnergySecondDiff_XX(int m) {
  double Energy = 0;
  for (int i = 0; i < R2points.size(); i++) {
    if (i != m) {
      Energy +=
          k[m][i] * (1 - (l[m][i] * pow((R2points[m].y - R2points[i].y), 2)) /
                             pow((pow((R2points[m].x - R2points[i].x), 2) +
                                  pow((R2points[m].y - R2points[i].y), 2)),
                                 1.5));
    }
  }
  return Energy;
}

double GraphBuilder::GetEnergySecondDiff_XY(int m) {
  double Energy = 0;
  for (int i = 0; i < R2points.size(); i++) {
    if (i != m) {
      Energy += k[m][i] * ((l[m][i] * (R2points[m].y - R2points[i].y) *
                            (R2points[m].x - R2points[i].x)) /
                           pow(pow((R2points[m].x - R2points[i].x), 2) +
                                   pow((R2points[m].y - R2points[i].y), 2),
                               1.5));
    }
  }
  return Energy;
}

double GraphBuilder::GetEnergySecondDiff_YY(int m) {
  double Energy = 0;
  for (int i = 0; i < R2points.size(); i++) {
    if (i != m) {
      Energy +=
          k[m][i] * (1 - (l[m][i] * pow((R2points[m].x - R2points[i].x), 2)) /
                             pow(pow((R2points[m].x - R2points[i].x), 2) +
                                     pow((R2points[m].y - R2points[i].y), 2),
                                 1.5));
    }
  }
  return Energy;
}

std::vector<point> GraphBuilder::GetPoints() {
  double epsilon = 1;
  while (true) {
    double max_delta = -90328409238409320;
    int delta_name = -1;
    for (int m = 0; m < R2points.size(); m++) {
      double new_delta =
          pow(pow(GetEnergyDiff_X(m), 2) + pow(GetEnergyDiff_Y(m), 2), 0.5);
      if (max_delta < new_delta) {
        max_delta = new_delta;
        delta_name = m;
      }
    }

    if (max_delta < epsilon) {
      break;
    }

    int iter_counter = 0;
    while (max_delta > epsilon) {
      double d = GetEnergyDiff_X(delta_name);
      double e = GetEnergyDiff_Y(delta_name);
      double a = GetEnergySecondDiff_XX(delta_name);
      double c = GetEnergySecondDiff_XY(delta_name);
      double b = GetEnergySecondDiff_YY(delta_name);
      double delta_y = (d * c - e * a) / (b * a - c * c);
      double delta_x = (-d - c * delta_y) / a;
      R2points[delta_name].x += delta_x;
      R2points[delta_name].y += delta_y;
      max_delta = pow(pow(GetEnergyDiff_X(delta_name), 2) +
                          pow(GetEnergyDiff_Y(delta_name), 2),
                      0.5);
    }
    iter_counter++;
    if (iter_counter > 10000) {
      break;
    }
  }
  double middle_x = 0;
  double middle_y = 0;

  for (int i = 0; i < R2points.size(); i++) {
    middle_x += (int)(R2points[i].x);
    middle_y += (int)(R2points[i].y);
  }

  middle_x /= R2points.size();
  middle_y /= R2points.size();

  double min_x = 5498494985;
  double min_y = 6546546546;

  for (int i = 0; i < R2points.size(); i++) {
    R2points[i].x -= middle_x;
    R2points[i].y -= middle_y;
    if (R2points[i].x < min_x) {
      min_x = R2points[i].x;
    }
    if (R2points[i].y < min_y) {
      min_y = R2points[i].y;
    }
  }
  for (int i = 0; i < R2points.size(); i++) {
    R2points[i].x -= min_x - 40;
    // use C++ (?)
    R2points[i].x = (int)R2points[i].x;
    R2points[i].y -= min_y - 40;
    R2points[i].y = (int)R2points[i].y;
  }
  std::cout << "Calculated the positions of the vertexes\n";

  return R2points;
}