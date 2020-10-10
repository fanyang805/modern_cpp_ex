#include "kMeans.hpp"
#include "utils.hpp"
#include <algorithm>
#include <iostream>

using namespace cv;

namespace ipb {

cv::Mat kMeans(const std::vector<cv::Mat> &descriptors, int num_clusters,
               int max_iter) {

  Mat mat_data = Vec_MatToMat(descriptors);
  Mat bestLabels = Mat(mat_data.rows, 1, CV_32SC1);
  Mat centers = Mat(num_clusters, mat_data.cols, mat_data.type());
  // std::cout << mat_data << std::endl;
  // double sum =
  kmeans(
      mat_data, num_clusters, bestLabels,
      cv::TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, max_iter, 1.0),
      3, KMEANS_PP_CENTERS, centers);
  // std::cout << sum << std::endl;
  return centers;
}

cv::Mat kMeans(const Mat &mat_data, int num_clusters, int max_iter) {

  Mat bestLabels = Mat(mat_data.rows, 1, CV_32SC1);
  Mat centers = Mat(num_clusters, mat_data.cols, mat_data.type());
  kmeans(
      mat_data, num_clusters, bestLabels,
      cv::TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, max_iter, 1.0),
      3, KMEANS_PP_CENTERS, centers);
  return centers;
}

} // namespace ipb

// cv::Mat kMeans(const std::vector<cv::Mat> &descriptors, int num_clusters,
//                int max_iter) {
//   // randomly select centers from the given descriptors
//   std::vector<Mat> vec_center(num_clusters);
//   std::srand(static_cast<unsigned int>(std::time(nullptr)));
//   for (int i = 0; i < num_clusters; ++i) {
//     int id = rand_num(0, num_clusters - 1);
//     descriptors[id].copyTo(vec_center[i]);
//   }

// std::vector<double> vec_dis(descriptors.size());
// std::vector<int> vec_center_id(descriptors.size());
// int des_id = 0;
// for (const auto &mat : descriptors) {
//   for (const auto &center : vec_center) {
//     vec_dis[des_id] = euclidean_dis_sq<float>(mat, center);
//   }
//   auto min_center = std::min_element(vec_dis.begin(), vec_dis.end());
// }
// }