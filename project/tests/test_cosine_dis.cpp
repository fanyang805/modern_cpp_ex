#include <iostream>
#include <opencv2/core.hpp>

#include "utils.hpp"

using namespace cv;

int main() {
  float arr1[] = {1, 1, 1, 1, 1};
  float arr2[] = {2, 2, 2, 2, 2};
  float arr3[] = {4, 6, 8, 3, 7};

  Mat mat1 = Mat(1, 5, CV_32FC1, arr1);
  Mat mat2 = Mat(1, 5, CV_32FC1, arr2);
  Mat mat3 = Mat(1, 5, CV_32FC1, arr3);

  std::cout << "The cosine distance of mat1 and mat2 is "
            << bovw::cosine_dis(mat1, mat2) << std::endl;
  std::cout << "The cosine distance of mat1 and mat3 is "
            << bovw::cosine_dis(mat1, mat3) << std::endl;
  std::cout << "The cosine distance of mat2 and mat3 is "
            << bovw::cosine_dis(mat2, mat3) << std::endl;

  std::cout << "The square of euclidean distance of mat1 and mat2 is "
            << bovw::euclidean_dis_sq(mat1, mat2) << std::endl;
  std::cout << "The square of euclidean distance of mat1 and mat3 is "
            << bovw::euclidean_dis_sq(mat1, mat3) << std::endl;
  std::cout << "The square of euclidean distance of mat2 and mat3 is "
            << bovw::euclidean_dis_sq(mat2, mat3) << std::endl;

  return 0;
}