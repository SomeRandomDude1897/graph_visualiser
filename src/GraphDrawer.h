#include <cstdint>
#include <map>
#include <vector>

#include "GraphBuilder.h"

#pragma pack(push, 1)

struct FileHeader {
  uint16_t file_type{0x4D42};
  uint32_t file_size{0};
  uint16_t reserved_1{0};
  uint16_t reserved_2{0};
  uint32_t offset_data{54};
};

struct InfoHeader {
  uint32_t header_size{40};
  int32_t width{0};
  int32_t height{0};
  uint16_t planes{1};
  uint16_t bit_count{24};
  uint32_t compression{0};
  uint32_t size_image{0};
  int32_t x_pixels_per_meter{2835};
  int32_t y_pixels_per_meter{2835};
  uint32_t colors_used{0};
  uint32_t colors_important{0};
};

struct pixel {
  uint8_t b{0};
  uint8_t g{0};
  uint8_t r{0};
};

#pragma pack(pop)

class GraphDrawer {
 public:
  void DrawGraph(std::vector<point>, std::vector<vertex>);
};