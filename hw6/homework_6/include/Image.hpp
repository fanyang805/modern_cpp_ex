#ifndef IMAGE_HPP_
#define IMAGE_HPP_

#include "io_tools.hpp"
#include <cstddef>
#include <string>
#include <vector>

namespace igg {

class Image {
private:
  int rows_;
  int cols_;

  std::vector<uint8_t> data_;

public:
  // Constructor
  Image() : rows_(0), cols_(0), data_{} {}
  Image(const int &para_rows, const int &para_cols)
      : rows_(para_rows), cols_(para_cols), data_(para_rows * para_cols, 0) {}

  // Member functions
  const int &rows() const { return rows_; }
  const int &cols() const { return cols_; }
  const uint8_t &at(int row, int col) const {
    return data_[row * cols_ + col];
  };
  uint8_t &at(int row, int col) { return data_[row * cols_ + col]; };
  bool FillFromPgm(const std::string &);
  void WriteToPgm(const std::string &) const;
  std::vector<float> ComputeHistogram(int) const;
  void DownScale(int);
  void UpScale(int);
};

} // namespace igg

#endif