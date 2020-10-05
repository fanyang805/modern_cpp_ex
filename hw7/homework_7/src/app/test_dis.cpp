#include <iostream>
#include <opencv2/core.hpp>
#include <utils.hpp>

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

int main() {
  std::vector<cv::Mat> &data = GetDummyData();
  Mat mat_data = ipb::Vec_MatToMat(data);
  std::cout << mat_data.row(0) << std::endl;
  std::cout << mat_data.row(5) << std::endl;

  double dis = ipb::euclidean_dis_sq<float>(mat_data.row(0), mat_data.row(5));
  std::cout << dis << std::endl;
  return 0;
}