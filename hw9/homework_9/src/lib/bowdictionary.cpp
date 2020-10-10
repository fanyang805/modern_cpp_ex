#include "bowdictionary.hpp"

#include <iostream>

#include <opencv2/core.hpp>

#include "kMeans.hpp"

using namespace cv;

namespace ipb {

bool BowDictionary::need_update(const int &max_iterations, const int &dict_size,
                                const std::vector<cv::Mat> &descriptors,
                                const int &total_features) const {
  bool result = true;
  if (descriptors.size() == 0) {
    std::cerr << "The descriptors are empty!\n";
    result = false;
  }

  if (max_iterations <= 0) {
    std::cerr << "The number of iteration should be a positive integer!\n";
    result = false;
  }

  if (dict_size > total_features) {
    std::cerr << "The size of dictionary" << dict_size
              << " cannot be larger than the "
                 "descriptors "
              << (int)descriptors.size() << "!\n";
    result = false;
  }

  return result;
}

// void BowDictionary::set_max_iterations(const int &max_iterations) {
//   if (!need_update(max_iterations, dict_size_, descriptors_,
//   total_features_)) {
//     return;
//   }

//   dictionary_ = kMeans(descriptors_, dict_size_, max_iterations);
//   max_iterations_ = max_iterations;
// }

// void BowDictionary::set_size(const int &dict_size) {
//   if (!need_update(max_iterations_, dict_size, descriptors_,
//   total_features_)) {
//     return;
//   }

//   dictionary_ = kMeans(descriptors_, dict_size, max_iterations_);
//   dict_size_ = dict_size;
// }

// void BowDictionary::set_descriptors(const std::vector<cv::Mat> &descriptors)
// {
//   Mat mat_data = Vec_MatToMat(descriptors);
//   int total_features = mat_data.rows;

//   if (!need_update(max_iterations_, dict_size_, descriptors, total_features))
//   {
//     return;
//   }

//   dictionary_ = kMeans(mat_data, dict_size_, max_iterations_);
//   descriptors_ = descriptors;
//   total_features_ = total_features;
// }

void BowDictionary::build(const int &max_iterations, const int &dict_size,
                          const std::vector<cv::Mat> &descriptors) {
  Mat mat_data = Vec_MatToMat(descriptors);
  int total_features = mat_data.rows;

  if (!need_update(max_iterations, dict_size, descriptors, total_features)) {
    return;
  }
  vocabulary_ = kMeans(mat_data, dict_size, max_iterations);

  // max_iterations_ = max_iterations;
  // dict_size_ = dict_size;
  // descriptors_ = descriptors;
  // total_features_ = total_features;
}

}  // namespace ipb