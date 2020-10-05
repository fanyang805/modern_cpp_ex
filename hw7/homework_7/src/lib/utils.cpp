#include "utils.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <opencv2/core/mat.hpp>
#include <vector>

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

} // namespace ipb