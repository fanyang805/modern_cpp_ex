#include "kMeans.hpp"
#include "utils.hpp"
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace ipb;

cv::Mat GetAllFeatures() {
  // init some parameters
  const int rows_num = 1;
  const int cols_num = 10;
  Mat data;

  for (int i = 0; i < 100; i += 20) {
    for (size_t j = 0; j < 5; j++) {
      data.push_back(Mat_<float>(rows_num, cols_num, i));
    }
  }

  return data;
}

cv::Mat Get18Kmeans() {
  // init some parameters
  const int rows_num = 1;
  const int cols_num = 10;
  Mat data;

  for (int i = 0; i < 100; i += 20) {
    for (size_t j = 0; j < 3; j++) {
      data.push_back(Mat_<float>(rows_num, cols_num, i));
    }
  }

  return data;
}

cv::Mat Get5Kmeans() {
  // init some parameters
  const int rows_num = 1;
  const int cols_num = 10;
  Mat data;

  for (int i = 0; i < 100; i += 20) {
    Mat_<float> vec(rows_num, cols_num, i);
    data.push_back(vec);
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

cv::Mat Get2Kmeans() {
  // init some parameters
  const int rows_num = 1;
  const int cols_num = 10;
  Mat data;

  data.push_back(Mat_<float>(rows_num, cols_num, 20.000002F));
  data.push_back(Mat_<float>(rows_num, cols_num, 70.0F));

  return data;
}

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
  // std::cout << mat_data << std::endl;

  int K = 3;

  Mat bestLabels = Mat(mat_data.rows, 1, CV_32SC1);
  Mat centers = Mat(K, mat_data.cols, CV_32FC1);

  double sum =
      kmeans(mat_data, K, bestLabels,
             cv::TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 10, 1.0),
             3, cv::KMEANS_RANDOM_CENTERS, centers);
  // KMEANS_RANDOM_CENTERS
  // cv::KMEANS_PP_CENTERS
  // std::cout << centers << std::endl;

  Mat_<float> result(mat_data.rows, mat_data.cols, 0.0f);
  for (int i = 0; i < result.rows; ++i) {
    centers.row(bestLabels.at<int>(i)).copyTo(result.row(i));
  }

  Mat centroids = centers;
  cv::sort(centroids, centroids, cv::SORT_EVERY_COLUMN + cv::SORT_ASCENDING);

  // std::cout << "------------" << std::endl;
  // std::cout << bestLabels << std::endl;
  std::cout << "------------" << std::endl;
  std::cout << centers << std::endl;
  std::cout << "------------" << std::endl;
  std::cout << sum << std::endl;
  // std::cout << result << std::endl;
  // std::cout << "------------" << std::endl;

  // std::cout << "GetDummyData():\n" << GetDummyData() << std::endl;
  // std::cout << "GetAllFeatures():\n" << GetAllFeatures() << std::endl;
  // std::cout << "Get18Kmeans()\n" << Get18Kmeans() << std::endl;
  // std::cout << "Get5Kmeans():\n" << Get5Kmeans() << std::endl;
  // std::cout << "Get3Kmeans():\n" << Get3Kmeans() << std::endl;
  // std::cout << "Get2Kmeans():\n" << Get2Kmeans() << std::endl;

  Mat centroid = ipb::kMeans(mat_data, 3, 10);

  std::cout << "-------------\n";
  std::cout << centroid << std::endl;

  return 0;
}