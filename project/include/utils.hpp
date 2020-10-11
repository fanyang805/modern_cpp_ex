#ifndef UTILS_HPP_
#define UTILS_HPP_
#include <algorithm>
#include <opencv2/core.hpp>
#include <string>
#include <vector>

namespace bovw {

template <typename Tp>
bool inline mat_are_equal(const cv::Mat &m1, const cv::Mat &m2) {
  return std::equal(m1.begin<Tp>(), m1.end<Tp>(), m2.begin<Tp>());
}

const cv::Mat compute_sifts(const std::string &);

const std::vector<std::string> get_sequence(const std::string &img_path,
                                            const std::string &extension,
                                            int min_num, int max_num);

} // namespace bovw

#endif // UTILS_HPP_
