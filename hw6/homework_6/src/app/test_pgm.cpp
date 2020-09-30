#include "Image.hpp"
#include <iostream>
using igg::Image;

int main() {
  Image img;
  bool res = img.FillFromPgm("data/lena.ascii.pgm");
  std::cout << "Read success: " << std::boolalpha << res << std::endl;
  std::cout << img.rows() << " " << img.cols() << std::endl;
  return 0;
}