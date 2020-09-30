#include "Image.hpp"
#include <iostream>

int main() {
  const Image img1;
  std::cout << img1.rows() << " " << img1.cols() << std::endl;

  const Image img2(10, 5);
  std::cout << img2.rows() << " " << img2.cols() << std::endl;
  for (int r = 0; r < img2.rows(); ++r) {
    for (int c = 0; c < img2.cols(); ++c) {
      std::cout << unsigned(img2.at(r, c)) << "   ";
    }
    std::cout << std::endl;
  }
  Image img3(Image{5, 5});
  img3.at(0, 0) = 10;
  for (int r = 0; r < img3.rows(); ++r) {
    for (int c = 0; c < img3.cols(); ++c) {
      std::cout << unsigned(img3.at(r, c)) << "   ";
    }
    std::cout << std::endl;
  }
  return 0;
}