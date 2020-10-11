#include "utils.hpp"
#include <iomanip>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/xfeatures2d.hpp>

using namespace cv;

namespace bovw {

const cv::Mat compute_sifts(const std::string &filename) {
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

} // namespace bovw