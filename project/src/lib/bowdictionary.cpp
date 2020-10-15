#include "bowdictionary.hpp"
#include "kMeans.hpp"

#include <iostream>
#include <opencv2/core.hpp>

using namespace cv;

namespace bovw {

// bool BowDictionary::need_update(const int &max_iterations, const int
// &dict_size,
//                                 const std::vector<cv::Mat> &descriptors,
//                                 const int &total_features) const {
//   bool result = true;
//   if (descriptors.size() == 0) {
//     std::cerr << "The descriptors are empty!\n";
//     result = false;
//   }

//   if (max_iterations <= 0) {
//     std::cerr << "The number of iteration should be a positive integer!\n";
//     result = false;
//   }

//   if (dict_size > total_features) {
//     std::cerr << "The size of dictionary" << dict_size
//               << " cannot be larger than the "
//                  "descriptors "
//               << (int)descriptors.size() << "!\n";
//     result = false;
//   }

//   return result;
// }

void BowDictionary::build(const int &max_iterations, const int &dict_size,
                          const std::vector<cv::Mat> &descriptors) {
  Mat mat_data = Vec_MatToMat(descriptors);
  int total_features = mat_data.rows;

  // Check if the new dictionary can be built
  if (descriptors.size() == 0) {
    std::cerr << "The descriptors are empty!\n";
    return;
  }

  if (max_iterations <= 0) {
    std::cerr << "The number of iteration should be a positive integer!\n";
    return;
  }

  if (dict_size > total_features) {
    std::cerr << "The size of dictionary" << dict_size
              << " cannot be larger than the "
                 "descriptors "
              << (int)descriptors.size() << "!\n";
    return;
  }

  auto [vocabulary, bestLabels] = kMeans(mat_data, dict_size, max_iterations);
  vocabulary_ = vocabulary.clone();
  bestLabels_ = bestLabels.clone();
}

} // namespace bovw