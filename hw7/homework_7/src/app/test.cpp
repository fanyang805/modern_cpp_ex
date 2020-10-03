#include "utils.hpp"
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace ipb;

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

// Mat Vec_MatToMat(const std::vector<Mat> &vec_mat) {
//   Mat mat = Mat::zeros(vec_mat.size() * vec_mat[0].rows, vec_mat[0].cols,
//                        vec_mat[0].type());
//   int mt_rows = vec_mat[0].rows;
//   // for (const auto &mt : vec_mat) {
//   for (int mt_id = 0; mt_id < (int)vec_mat.size(); ++mt_id) {
//     (vec_mat[mt_id])
//         .copyTo(mat.rowRange(mt_id * mt_rows, (mt_id + 1) * mt_rows));
//   }
//   return mat;
// }

int main() {
  std::vector<cv::Mat> data = GetDummyData();

  Mat mat_data = Vec_MatToMat(data);

  // Mat mat_data = Mat(data.size(), data[0].cols, CV_32FC1);
  // for (int i = 0; i < (int)data.size(); ++i) {
  //   data[i].copyTo(mat_data.row(i));
  // }
  // std::cout << "----------------\n";
  std::cout << mat_data << std::endl;

  int K = 15;

  Mat bestLabels = Mat(mat_data.rows, 1, CV_32SC1);
  Mat centers = Mat(K, mat_data.cols, CV_32FC1);

  kmeans(mat_data, K, bestLabels,
         cv::TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 10, 1.0), 3,
         cv::KMEANS_PP_CENTERS, centers);
  // std::cout << centers << std::endl;

  Mat_<float> result(mat_data.rows, mat_data.cols, 0.0f);
  for (int i = 0; i < result.rows; ++i) {
    centers.row(bestLabels.at<int>(i)).copyTo(result.row(i));
  }

  std::cout << "------------" << std::endl;
  std::cout << bestLabels << std::endl;
  std::cout << "------------" << std::endl;
  std::cout << centers << std::endl;
  std::cout << "------------" << std::endl;
  std::cout << result << std::endl;
  std::cout << "------------" << std::endl;
  return 0;
}