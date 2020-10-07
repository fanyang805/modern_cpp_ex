#ifndef IMAGE_HPP_
#define IMAGE_HPP_

#include <cstddef>
#include <memory>
#include <string>
#include <vector>

#include "strategy.hpp"

namespace igg {

class Image {
 private:
  int rows_{};
  int cols_{};

  struct Pixel {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    Pixel() = default;
    Pixel(uint8_t r, uint8_t g, uint8_t b) : red(r), green(g), blue(b) {}
  };
  std::vector<Pixel> data_{};
  std::shared_ptr<IoStrategy> strategy_ptr_ = nullptr;

 public:
  // Constructor
  Image() = default;
  Image(const int &para_rows, const int &para_cols)
      : rows_(para_rows),
        cols_(para_cols),
        data_(para_rows * para_cols, {0, 0, 0}) {}

  // Member functions
  [[nodiscard]] const int &rows() const { return rows_; }
  [[nodiscard]] const int &cols() const { return cols_; }
  [[nodiscard]] const Pixel &at(int row, int col) const {
    return data_[row * cols_ + col];
  };
  Pixel &at(int row, int col) { return data_[row * cols_ + col]; };
  bool ReadFromDisk(const std::string &);
  void WriteToDisk(const std::string &) const;
  void DownScale(int);
  void UpScale(int);
  void SetIoStrategy(const std::shared_ptr<IoStrategy> &strategy_ptr) {
    strategy_ptr_ = strategy_ptr;
  }
};

}  // namespace igg

#endif