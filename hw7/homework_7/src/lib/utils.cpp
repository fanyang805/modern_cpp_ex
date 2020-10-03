#include "utils.hpp"
#include <opencv2/core/mat.hpp>
#include <vector>

namespace ipb {

cv::Mat Vec_MatToMat(const std::vector<cv::Mat> &vec_mat) {
  cv::Mat mat = cv::Mat::zeros(vec_mat.size() * vec_mat[0].rows,
                               vec_mat[0].cols, vec_mat[0].type());
  int mt_rows = vec_mat[0].rows;
  // for (const auto &mt : vec_mat) {
  for (int mt_id = 0; mt_id < (int)vec_mat.size(); ++mt_id) {
    (vec_mat[mt_id])
        .copyTo(mat.rowRange(mt_id * mt_rows, (mt_id + 1) * mt_rows));
  }
  return mat;
}
} // namespace ipb