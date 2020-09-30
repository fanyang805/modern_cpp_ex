#include "Image.hpp"
#include <iostream>
using igg::Image;

int main() {
  Image img;
  img.FillFromPgm("tests/data/dummy_file.pgm");
  img.UpScale(3);
  std::cout << img.rows() << " " << img.cols() << std::endl;
  for (int r = 0; r < img.rows(); ++r) {
    for (int c = 0; c < img.cols(); ++c) {
      std::cout << unsigned(img.at(r, c)) << "   ";
    }
    std::cout << std::endl;
  }
}