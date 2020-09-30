#include "Image.hpp"
#include <iostream>
using igg::Image;

int main() {
  Image img;
  img.FillFromPgm("tests/data/dummy_file.pgm");
  const Image &img_ref = img;
  int size = 1;
  auto hist = img_ref.ComputeHistogram(size);
  //   std::cout << hist[0] << " " << hist[9] << std::endl;
  std::cout << hist.front() << std::endl;
  return 0;
}