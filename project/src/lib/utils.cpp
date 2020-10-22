#include "utils.hpp"
#include "histogram.hpp"

#include <cmath>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <vector>

using namespace cv;

namespace bovw {

const cv::Mat compute_sifts(const std::string &filename) {
  namespace fs = std::filesystem;
  if (!fs::exists(filename)) {
    std::cerr << "The file " << filename << " does not exist!\n";
    return cv::Mat();
  }
  const cv::Mat img_mat = cv::imread(filename, cv::IMREAD_GRAYSCALE);
  auto detector = cv::SiftFeatureDetector::create();
  std::vector<cv::KeyPoint> vec_keypoint;
  detector->detect(img_mat, vec_keypoint);

  cv::Mat descriptors;
  auto extractor = cv::SiftDescriptorExtractor::create();
  extractor->compute(img_mat, vec_keypoint, descriptors);

  return descriptors;
}

const std::vector<std::string> get_sequence(const std::string &img_path,
                                            const std::string &extension,
                                            int min_num, int max_num) {
  const std::string &prefix = "imageCompressedCam0_";
  std::vector<std::string> img_sequence;
  img_sequence.reserve(max_num - min_num + 1);

  auto to_format = [](const int number) {
    std::stringstream ss;
    ss << std::setw(7) << std::setfill('0') << number;
    return ss.str();
  };

  for (int idx = min_num; idx <= max_num; ++idx) {
    const std::string &img_id = to_format(idx * 10);
    const std::string &filename = img_path + prefix + img_id + extension;
    img_sequence.emplace_back(filename);
  }

  return img_sequence;
}

float cosine_dis(const Mat &mat1, const Mat &mat2) {

  float dot_product = mat1.dot(mat2);
  float sq_norm1 = mat1.dot(mat1);
  float sq_norm2 = mat2.dot(mat2);
  float cosine_simiarity = dot_product / std::sqrt(sq_norm1 * sq_norm2);
  return 1 - cosine_simiarity;
}

float euclidean_dis_sq(const Mat &mat1, const Mat &mat2) {

  Mat mat_sub = mat1 - mat2;
  return mat_sub.dot(mat_sub);
}

Mat Vec_MatToMat(const std::vector<Mat> &vec_mat) {
  int num_row = 0;
  int num_col = vec_mat[0].cols;

  for (const auto &mat_ele : vec_mat) {
    num_row += mat_ele.rows;
  }

  Mat mat = Mat::zeros(num_row, num_col, vec_mat[0].type());
  int row_id = 0;
  for (int mt_id = 0; mt_id < (int)vec_mat.size(); ++mt_id) {
    int mat_rows = vec_mat[mt_id].rows;
    (vec_mat[mt_id]).copyTo(mat.rowRange(row_id, row_id + mat_rows));
    row_id += mat_rows;
  }
  return mat;
}

std::vector<Mat> gen_blabels(const cv::Mat &bestLabels,
                             const std::vector<cv::Mat> &descriptors) {
  size_t num_img = descriptors.size();
  std::vector<Mat> blabels_for_each;
  blabels_for_each.reserve(num_img);
  int start_idx = 0;
  int end_idx = 0;
  for (const auto &img_descriptor : descriptors) {
    start_idx = end_idx;
    end_idx = start_idx + img_descriptor.rows;
    blabels_for_each.emplace_back(bestLabels.rowRange(start_idx, end_idx));
  }
  return blabels_for_each;
}

std::vector<bovw::Histogram> gen_vechist_from_csv(const std::string &filename) {

  std::vector<bovw::Histogram> vec_hist;
  std::ifstream in(filename, std::ios_base::in);
  if (!in) {
    std::cerr << "Cannot read .csv file: " << filename << std::endl;
    return std::vector<bovw::Histogram>();
  }

  std::string line;
  while (std::getline(in, line) && !line.empty()) {
    std::vector<int> data;
    // std::cout << line << std::endl;
    std::stringstream ss{line};
    std::string str_counts;
    while (std::getline(ss, str_counts, ',')) {
      int counts = std::stoi(str_counts);
      data.emplace_back(counts);
      // std::cout << counts << " ";
    }
    vec_hist.emplace_back(Histogram(data));
  }

  for (auto &hist : vec_hist) {
    hist.set_img_num(vec_hist.size());
  }

  return vec_hist;
}

} // namespace bovw