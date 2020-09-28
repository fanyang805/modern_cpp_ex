#include "convert_dataset.hpp"
#include "serialize.hpp"
#include <filesystem>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <vector>

namespace fs = std::filesystem;
namespace ipb::serialization::sifts {

void ConvertDataset(const std::filesystem::path &img_path) {

  // The path to the binary files
  const std::string bin_path =
      img_path.parent_path().parent_path().string() + "/bin/";
  fs::create_directories(bin_path);
  // Iterate through each file in the given path
  for (const auto &entry : fs::directory_iterator(img_path)) {

    // Make sure the extension is png
    const std::string extension = entry.path().extension();
    if (extension != ".png") {
      std::cout << "The image file " << entry.path().filename()
                << " is not .png file.\n";
      continue;
    }

    // Compute the SIFT descripter
    const cv::Mat img_mat = cv::imread(entry.path(), cv::IMREAD_GRAYSCALE);
    auto detector = cv::SiftFeatureDetector::create();
    std::vector<cv::KeyPoint> vec_keypoint;
    detector->detect(img_mat, vec_keypoint);

    cv::Mat descriptors;
    auto extractor = cv::SiftDescriptorExtractor::create();
    extractor->compute(img_mat, vec_keypoint, descriptors);

    // Serialize descripter
    const std::string bin_name = entry.path().stem().string() + ".bin";
    const std::string des_bin_path = bin_path + bin_name;
    // std::cout << des_bin_path << std::endl;
    ipb::serialization::Serialize(descriptors, des_bin_path);
    descriptors.release();
  }
}

std::vector<cv::Mat> LoadDataset(const std::filesystem::path &bin_path) {

  std::vector<cv::Mat> vec_des;
  // Iterate through the give directory
  for (const auto &entry : fs::directory_iterator(bin_path)) {
    // Check the file extension
    const std::string extension = entry.path().extension();
    if (extension != ".bin") {
      std::cout << "The file " << entry.path().filename()
                << " is not .bin file.\n";
      continue;
    }
    vec_des.emplace_back(ipb::serialization::Deserialize(entry.path()));
  }

  return vec_des;
}

} // namespace ipb::serialization::sifts