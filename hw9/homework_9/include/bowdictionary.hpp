#ifndef BOWDICTIONARY_
#define BOWDICTIONARY_

#include <vector>

#include <opencv2/core.hpp>

namespace ipb {

class BowDictionary {
 private:
  // int max_iterations_;
  // int dict_size_;
  // std::vector<cv::Mat> descriptors_;
  cv::Mat vocabulary_;
  // int total_features_;
  BowDictionary() = default;
  ~BowDictionary() = default;
  BowDictionary(const int &max_iterations, const int &dict_size,
                const std::vector<cv::Mat> &descriptors) {
    build(max_iterations, dict_size, descriptors);
  }

 public:
  BowDictionary(const BowDictionary &) = delete;
  void operator=(const BowDictionary &) = delete;
  static BowDictionary &GetInstance() {
    static BowDictionary instance;
    return instance;
  };

  // Getter funcs
  // const int &max_iterations() const { return max_iterations_; };
  const int &size() const { return vocabulary_.rows; };
  // const std::vector<cv::Mat> &descriptors() const { return descriptors_; };
  const cv::Mat vocabulary(const int &ind) const {
    return vocabulary_.row(ind);
  };
  const cv::Mat vocabulary() const { return vocabulary_; };
  // int total_features() const { return total_features_; };
  bool empty() const { return (size() == 0); }

  // Setter funcs
  // void set_max_iterations(const int &max_iterations);
  // void set_size(const int &dict_size);
  // void set_descriptors(const std::vector<cv::Mat> &descriptors);
  void build(const int &max_iterations, const int &dict_size,
             const std::vector<cv::Mat> &descriptors);
  void set_vocabulary(const cv::Mat &vocabulary) { vocabulary_ = vocabulary; }

  // Other utility funcs
  bool need_update(const int &max_iterations, const int &dict_size,
                   const std::vector<cv::Mat> &descriptors,
                   const int &total_features) const;
};

}  // namespace ipb

#endif