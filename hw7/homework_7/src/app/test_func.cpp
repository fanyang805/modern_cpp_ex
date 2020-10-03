#include <iostream>
// #include <opencv2/core/mat.hpp>
// #include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;

int main() {
  Mat_<float> mat(3, 3, 1.1f);
  Mat_<float> mat2(3, 3, 2.2f);
  mat2.row(1).copyTo(mat.row(0));
  std::cout << mat << std::endl;
  std::cout << mat2 << std::endl;
  // mat.row(0) *= 3;
  // std::cout << mat << std::endl;
  // std::cout << mat.size() << std::endl;
  // Mat_<float> mat1(mat.size(), 1.0);
  // std::cout << mat1 << std::endl;
  return 0;
}