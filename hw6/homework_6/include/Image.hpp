#ifndef IMAGE_HPP_
#define IMAGE_HPP_

// #include <bits/stdint-uintn.h>
#include "io_tools.hpp"
#include <cstddef>
#include <string>
#include <vector>

class Image {
private:
  int rows_;
  int cols_;
  uint8_t max_val_;
  std::vector<uint8_t> data_;

public:
  // Constructor
  Image() : rows_(0), cols_(0), max_val_(0), data_{} {}
  Image(const int &para_rows, const int &para_cols)
      : rows_(para_rows), cols_(para_cols), max_val_(0),
        data_(para_rows * para_cols, 0) {}
  // Image(const int &para_rows, const int &para_cols, const uint8_t &para_max,
  //       const std::vector<uint8_t> &para_data)
  //     : rows_(para_rows), cols_(para_cols), max_val_(para_max),
  //       data_(para_data) {}

  // Member functions
  const int &rows() const { return rows_; }
  const int &cols() const { return cols_; }
  const uint8_t &at(int row, int col) const { return data_[row + col]; };
  uint8_t &at(int row, int col) { return data_[row * cols_ + col]; };
  bool FillFromPgm(const std::string &);
  void WriteToPgm(const std::string &);
  std::vector<float> ComputeHistogram(int) const;
};

#endif