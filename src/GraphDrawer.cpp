#include "GraphDrawer.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

std::vector<std::vector<pixel>> ReadFontImage(const char* filename) {
  std::vector<std::vector<pixel>> pixel_data;
  FILE* file = fopen(filename, "rb");

  FileHeader file_header;
  InfoHeader info_header;

  fread((char*)&file_header, 1, 14, file);
  fread((char*)&info_header, 1, 40, file);
  int size = info_header.width * info_header.height * 3;

  unsigned char* data_temp = new unsigned char[size];
  fread(data_temp, 1, size, file);

  pixel px;

  for (int h = 0; h < info_header.height; h++) {
    pixel_data.push_back({});
    for (int w = 0; w < info_header.width; w++) {
      px.b = data_temp[(h * info_header.width + w) * 3];
      px.g = data_temp[(h * info_header.width + w) * 3 + 1];
      px.r = data_temp[(h * info_header.width + w) * 3 + 2];
      pixel_data[h].push_back(px);
    }
  }
  delete[] data_temp;
  return pixel_data;
}

void GraphDrawer::DrawGraph(std::vector<point> R2points,
                            std::vector<vertex> vertexes) {
  int canvas_size_x = 0;
  int canvas_size_y = 0;

  for (int i = 0; i < R2points.size(); i++) {
    if (R2points[i].x > canvas_size_x) {
      canvas_size_x = R2points[i].x;
    }
    if (R2points[i].y > canvas_size_y) {
      canvas_size_y = R2points[i].y;
    }
  }
  canvas_size_x += 80 + canvas_size_x % 4;
  canvas_size_y += 80 + canvas_size_y % 4;

  FileHeader file_header;
  InfoHeader info_header;

  info_header.width = canvas_size_x;
  info_header.height = canvas_size_y;
  file_header.file_size = 54 + ((canvas_size_x) * (canvas_size_y)) * 4;
  info_header.size_image = (canvas_size_x) * (canvas_size_y);
  file_header.offset_data = 54;

  std::map<int, std::vector<std::vector<pixel>>> font_data;

  for (int i = 0; i < 10; i++) {
    std::string temp_string = "digits/" + std::to_string(i) + ".bmp";
    font_data[i] = ReadFontImage(temp_string.c_str());
  }

  std::map<int, std::vector<int>> to_paint;
  for (int y = 0; y < canvas_size_y; y++) {
    to_paint[y] = {};
  }
  for (int f = 0; f < vertexes.size(); f++) {
    int x_2 = R2points[vertexes[f].name].x;
    int y_2 = R2points[vertexes[f].name].y;
    // нарисуем кружочек вершины
    for (int y = y_2 - 4; y < y_2 + 4; y++) {
      for (int x = x_2 - 4; x < x_2 + 4; x++) {
        if (pow(pow(x - x_2, 2) + pow(y - y_2, 2), 0.5) <= 4) {
          to_paint[y].push_back(x);
        }
      }
    }
    //подпишем вершинки

    std::string symbols = std::to_string(R2points[vertexes[f].name].name + 1);
    for (int number = 0; number < symbols.size(); number++) {
      int symbol = (symbols[number]) - '0';
      for (int y = 0; y < 16; y++) {
        for (int x = 0; x < 16; x++) {
          if ((int)font_data[symbol][y][x].r != 255 &&
              (int)font_data[symbol][y][x].g != 255 &&
              (int)font_data[symbol][y][x].b != 255) {
            to_paint[y + y_2].push_back(x + x_2 + number * 12 + 10);
          }
        }
      }
    }
    for (int s = 0; s < vertexes[f].neighbours.size(); s++) {
      int x_1 = R2points[vertexes[f].neighbours[s]->name].x;
      int y_1 = R2points[vertexes[f].neighbours[s]->name].y;

      int min_vertex_y = std::min(y_1, y_2);
      int min_vertex_x = std::min(x_1, x_2);
      int max_vertex_y = std::max(y_1, y_2);
      int max_vertex_x = std::max(x_1, x_2);

      // нарисуем линии соединяющие вершины
      for (int y = min_vertex_y; y < max_vertex_y; y++) {
        for (int x = min_vertex_x; x < max_vertex_x; x++) {
          if (abs((y_2 - y_1) * x + (x_1 - x_2) * y + y_1 * x_2 - x_1 * y_2) /
                  (pow(pow((y_2 - y_1), 2) + pow((x_1 - x_2), 2), 0.5)) <
              2) {
            if (pow(pow(x - x_2, 2) + pow(y - y_2, 2), 0.5) > 6 &&
                pow(pow(x - x_1, 2) + pow(y - y_1, 2), 0.5) > 6) {
              to_paint[y].push_back(x);
            }
          }
        }
      }
    }
  }

  FILE* outfile = fopen("drawing.bmp", "wb");
  fwrite((const char*)&file_header, 1, 14, outfile);
  fwrite((const char*)&info_header, 1, 40, outfile);

  for (int y = 0; y < canvas_size_y; y++) {
    pixel* pixels = new pixel[canvas_size_x];
    for (int x = 0; x < canvas_size_x; x++) {
      pixel new_pix;
      bool flag = false;
      if (!flag) {
        new_pix.b = 255;
        new_pix.g = 255;
        new_pix.r = 255;
        pixels[x] = (new_pix);
      }
    }
    for (int i = 0; i < to_paint[y].size(); i++) {
      pixel new_pix;
      new_pix.b = 0;
      new_pix.g = 0;
      new_pix.r = 0;
      pixels[to_paint[y][i]] = (new_pix);
    }
    //(canvas_size_x)*(canvas_size_y) * 3
    fwrite(pixels, 1, (canvas_size_x)*3 + canvas_size_x % 4, outfile);
  }
  std::cout << "Finished drawing\n";
  return;
}