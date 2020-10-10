#ifndef UTILS_HPP_
#define UTILS_HPP_
#include <iostream>
#include <vector>

#include <opencv2/core.hpp>

int rand_num(int min, int max);

namespace ipb {
cv::Mat Vec_MatToMat(const std::vector<cv::Mat> &);

template <typename T>
double euclidean_dis_sq(const cv::Mat &mat1, const cv::Mat &mat2);
// #include "dis_imp.tpp"

}  // namespace ipb

#endif