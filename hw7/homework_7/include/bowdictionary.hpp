#ifndef BOWDICTIONARY_
#define BOWDICTIONARY_

#include <opencv2/core.hpp>
#include <vector>

namespace ipb {

class BowDictionary {
private:
  int max_iterations_;
  int dict_size_;
  std::vector<cv::Mat> descriptors_;
  cv::Mat dictionary_;
  int total_features_;
  BowDictionary() = default;
  ~BowDictionary() = default;
  BowDictionary(const int &max_iterations, const int &dict_size,
                const std::vector<cv::Mat> &descriptors)
      : max_iterations_(max_iterations), dict_size_(dict_size),
        descriptors_(descriptors) {}

public:
  BowDictionary(const BowDictionary &) = delete;
  void operator=(const BowDictionary &) = delete;
  static BowDictionary &GetInstance() {
    static BowDictionary instance;
    return instance;
  };

  // Getter funcs
  const int &max_iterations() const { return max_iterations_; };
  const int &size() const { return dict_size_; };
  const std::vector<cv::Mat> &descriptors() const { return descriptors_; };
  const cv::Mat vocabulary(const int &ind) { return dictionary_.row(ind); };
  int total_features() const { return total_features_; };
  bool empty() const { return (descriptors_.size() == 0); }

  // Setter funcs
  void set_max_iterations(const int &max_iterations);
  void set_size(const int &dict_size);
  void set_descriptors(const std::vector<cv::Mat> &descriptors);
  void set_params(const int &max_iterations, const int &dict_size,
                  const std::vector<cv::Mat> &descriptors);
  // Other utility funcs
  bool need_update(const int &max_iterations, const int &dict_size,
                   const std::vector<cv::Mat> &descriptors,
                   const int &total_features) const;
};

} // namespace ipb

#endif