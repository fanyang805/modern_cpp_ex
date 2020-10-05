#include "kMeans.hpp"
#include "opencv2/core.hpp"
#include <iostream>
#include <vector>

using namespace cv;

std::vector<cv::Mat> &GetDummyData() {
  // init some parameters
  const int rows_num = 1;
  const int cols_num = 10;
  static std::vector<Mat> data;

  for (int i = 0; i < 100; i += 20) {
    for (size_t j = 0; j < 5; j++) {
      data.push_back(Mat_<float>(rows_num, cols_num, i));
    }
  }

  return data;
}

cv::Mat Get3Kmeans() {
  // init some parameters
  const int rows_num = 1;
  const int cols_num = 10;
  Mat data;

  data.push_back(Mat_<float>(rows_num, cols_num, 0.0F));
  data.push_back(Mat_<float>(rows_num, cols_num, 30.0F));
  data.push_back(Mat_<float>(rows_num, cols_num, 70.0F));

  return data;
}

int main() {
  auto data = GetDummyData();
  auto descriptors = data;
  int num_clusters = 15;

  std::vector<Mat> vec_center(num_clusters);
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  for (int i = 0; i < num_clusters; ++i) {
    int id = rand_num(0, num_clusters - 1);
    std::cout << id << std::endl;
    descriptors[id].copyTo(vec_center[i]);
  }

  for (const auto &ele : vec_center) {
    std::cout << ele << std::endl;
  }

  return 0;
}