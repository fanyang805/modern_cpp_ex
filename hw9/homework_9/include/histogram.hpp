#ifndef HISTOGRAM_HPP_
#define HISTOGRAM_HPP_

#include <iostream>
#include <string>
#include <vector>

#include <opencv2/core.hpp>

#include "bowdictionary.hpp"

namespace ipb {

class Histogram {
  friend std::ostream &operator<<(std::ostream &os, const Histogram &hist_obj);

 private:
  std::vector<int> data_{};

 public:
  // Constructors
  Histogram() = default;
  explicit Histogram(const std::vector<int> &data) : data_(data){};
  Histogram(cv::Mat descriptors, const BowDictionary &dictionary);
  // Member functions
  const std::vector<int> &data() const { return data_; };
  size_t size() const { return data_.size(); };
  bool empty() const { return data_.empty(); };
  // Operators
  int &operator[](size_t idx) { return data_[idx]; };
  const int &operator[](size_t idx) const { return data_[idx]; };
  static Histogram ReadFromCSV(const std::string &filename);
  void WriteToCSV(const std::string &filename) const;
  // Iterators
  std::vector<int>::iterator begin() { return data_.begin(); };
  std::vector<int>::const_iterator begin() const { return data_.begin(); };
  std::vector<int>::const_iterator cbegin() const { return data_.cbegin(); };
  std::vector<int>::iterator end() { return data_.end(); };
  std::vector<int>::const_iterator end() const { return data_.end(); };
  std::vector<int>::const_iterator cend() const { return data_.cend(); };
};

}  // namespace ipb

#endif