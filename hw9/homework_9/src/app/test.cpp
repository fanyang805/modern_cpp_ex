#include <iostream>
#include <vector>

#include <opencv2/core.hpp>

#include "utils.hpp"

using namespace cv;

int main() {
  std::vector<uint8_t> vec{1, 2, 3, 4, 5};
  Mat data = Mat(vec, CV_8UC1).reshape(0, 1);

  uint8_t arr[5] = {255, 2, 3, 4, 5};
  Mat data2 = Mat(1, 5, CV_8UC1, arr);

  std::cout << data << std::endl;
  std::cout << data2 << std::endl;

  double ans = ipb::euclidean_dis_sq<uchar>(data, data2);
  std::cout << ans << std::endl;
  return 0;
}