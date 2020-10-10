#ifndef BOWDICTIONARY_
#define BOWDICTIONARY_

#include <vector>

#include <opencv2/core.hpp>

namespace ipb {

class BowDictionary {
 private:
  cv::Mat vocabulary_;
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
  const int &size() const { return vocabulary_.rows; };
  const cv::Mat vocabulary(const int &ind) const {
    return vocabulary_.row(ind);
  };
  const cv::Mat vocabulary() const { return vocabulary_; };
  bool empty() const { return (size() == 0); }

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