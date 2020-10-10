#include "utils.hpp"

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include <opencv2/core/mat.hpp>

int rand_num(int min, int max) {
  // std::srand(static_cast<unsigned int>(std::time(nullptr)));
  static constexpr double fraction{1.0 / (RAND_MAX + 1.0)};
  return min + (max - min + 1) * (std::rand() * fraction);
}

namespace ipb {

cv::Mat Vec_MatToMat(const std::vector<cv::Mat> &vec_mat) {
  int num_row = 0;
  int num_col = vec_mat[0].cols;

  for (const auto &mat_ele : vec_mat) {
    num_row += mat_ele.rows;
  }

  cv::Mat mat = cv::Mat::zeros(num_row, num_col, vec_mat[0].type());
  int row_id = 0;
  for (int mt_id = 0; mt_id < (int)vec_mat.size(); ++mt_id) {
    int mat_rows = vec_mat[mt_id].rows;
    (vec_mat[mt_id]).copyTo(mat.rowRange(row_id, row_id + mat_rows));
    row_id += mat_rows;
  }
  return mat;
}

template <typename T>
double euclidean_dis_sq(const cv::Mat &mat1, const cv::Mat &mat2) {
  if (mat1.rows != mat2.rows || mat1.cols != mat2.cols) {
    std::cerr << "Wrong dimensions of inputs!\n";
    return -1;
  }

  double dis_sq = 0;

  for (int col_id = 0; col_id < mat1.cols; ++col_id) {
    dis_sq += std::pow((mat1.at<T>(col_id) - mat2.at<T>(col_id)), 2);
  }

  return dis_sq;
}

template double euclidean_dis_sq<float>(const cv::Mat &mat1,
                                        const cv::Mat &mat2);

template double euclidean_dis_sq<uchar>(const cv::Mat &mat1,
                                        const cv::Mat &mat2);

}  // namespace ipb