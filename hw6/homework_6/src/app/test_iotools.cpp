#include "io_tools.hpp"
#include <iostream>
#include <string>

int main() {
  const std::string &file_name{"data/lena.ascii.pgm"};
  igg::io_tools::ImageData img = igg::io_tools::ReadFromPgm(file_name);

  int rows = img.rows;
  int cols = img.cols;
  std::vector<uint8_t> data = img.data;
  std::cout << img.data.size() << " " << rows * cols << std::endl;
  return 0;
}
