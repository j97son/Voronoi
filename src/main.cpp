#include <array>
#include <iostream>
#include <random>

#include "voronoi.hpp"

#include "CImg.h"
using namespace cimg_library;

struct Vertex {
  double x = 0.0;
  double y = 0.0;

  Vertex() = default;
  Vertex(double x, double y) : x(x), y(y) {}
  Vertex(double z) : x(z), y(z) {}

  friend std::ostream& operator<<(std::ostream& os, const Vertex& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
  }
};

int main() {
  CImg<unsigned char> image(800, 600, 1, 3, 255);
  std::array<Vertex, 20> sites;
  std::mt19937 gen(1);
  std::uniform_real_distribution<double> dist_x(0.0, 800.0);
  std::uniform_real_distribution<double> dist_y(0.0, 600.0);

  const unsigned char black[]{0, 0, 0};
  for (auto s : sites) {
    s = {dist_x(gen), dist_y(gen)};
    std::cout << s << "\n";
    image.draw_circle(s.x, s.y, 2, black);
  }
  image.save_imagemagick_external(
      "../images/"
      "blank_image.png");
  std::cout << "Saved!\n";
  return 0;
}
