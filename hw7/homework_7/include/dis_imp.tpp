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