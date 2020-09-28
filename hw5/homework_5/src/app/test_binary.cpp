#include "serialize.hpp"
#include "utils.hpp"
#include <filesystem>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

namespace fs = std::filesystem;
int main() {
  const std::string lenna_path = "data/lenna.png";
  const std::string lenna_bin_path = "data/lenna.bin";

  cv::Mat lenna_mat = cv::imread(lenna_path, cv::IMREAD_GRAYSCALE);

  if (lenna_mat.empty()) {
    std::cout << "Cannot read image.\n";
    return 1;
  }

  ipb::serialization::Serialize(lenna_mat, lenna_bin_path);

  std::cout << "Created binary? " << std::boolalpha
            << fs::exists(lenna_bin_path) << std::endl;

  auto lenna_mat_bin = ipb::serialization::Deserialize(lenna_bin_path);
  std::cout << "The lenna mat created from binary is empty? " << std::boolalpha
            << lenna_mat_bin.empty() << std::endl;
  std::cout << "The size of matrix is same with the original? "
            << lenna_mat_bin.size() << std::endl;
  std::cout << "The two matrices are same? " << std::boolalpha
            << mat_are_equal<uchar>(lenna_mat, lenna_mat_bin) << std::endl;
  cv::namedWindow("Window Name", cv::WINDOW_AUTOSIZE);
  cv::imshow("Window Name", lenna_mat_bin);

  cv::waitKey(0);
  fs::remove(lenna_bin_path);
  return 0;
}