#ifndef UTILS_HPP_
#define UTILS_HPP_
#include <opencv2/core.hpp>
#include <vector>

namespace ipb {
cv::Mat Vec_MatToMat(const std::vector<cv::Mat> &);
}

#endif