

#include "Image.hpp"

#include <algorithm>

namespace igg {

// Create Image obj from .pgm file
// filename is the path of .pgm file
bool Image::ReadFromDisk(const std::string &filename) {
  if (!strategy_ptr_) {
    exit(1);
  }
  igg::ImageData img_data = strategy_ptr_->Read(filename);
  rows_ = img_data.rows;
  cols_ = img_data.cols;
  data_ = std::vector<Pixel>(rows_ * cols_, {0, 0, 0});

  for (int r = 0; r < rows_; ++r) {
    for (int c = 0; c < cols_; ++c) {
      int idx = r * rows_ + c;
      data_[idx].red = img_data.data[0][idx];
      data_[idx].green = img_data.data[1][idx];
      data_[idx].blue = img_data.data[2][idx];
    }
  }

  return !(img_data.data.empty());
};

// Create .pgm file from Image obj
// filename is the path of
void Image::WriteToDisk(const std::string &filename) const {
  if (!strategy_ptr_) {
    exit(1);
  }
  ImageData img_data;
  img_data.rows = rows_;
  img_data.cols = cols_;
  img_data.max_val = 255;
  std::vector<uint8_t> red(img_data.rows * img_data.cols, 0);
  std::vector<uint8_t> green(img_data.rows * img_data.cols, 0);
  std::vector<uint8_t> blue(img_data.rows * img_data.cols, 0);
  for (int r = 0; r < img_data.rows; ++r) {
    for (int c = 0; c < img_data.cols; ++c) {
      int idx = r * img_data.cols + c;
      red[idx] = data_[idx].red;
      green[idx] = data_[idx].green;
      blue[idx] = data_[idx].blue;
    }
  }
  img_data.data = {red, green, blue};
  strategy_ptr_->Write(filename, img_data);
}

void Image::DownScale(int scale) {
  if (scale == 1) {
    return;
  }
  std::vector<Pixel> scaled_data(data_.size() / (scale * scale), {0, 0, 0});
  int row_ind = 0;
  int col_ind = 0;
  int scaled_row = rows_ / scale;
  int scaled_col = cols_ / scale;
  for (auto &pixel : scaled_data) {
    int row_ind_original = row_ind * scale;
    int col_ind_original = col_ind * scale;
    pixel = data_[row_ind_original * cols_ + col_ind_original];
    if (row_ind == scaled_row - 1) {
      row_ind = 0;
      ++col_ind;
    } else {
      ++row_ind;
    }
  }
  data_ = scaled_data;
  rows_ = scaled_row;
  cols_ = scaled_col;
};

void Image::UpScale(int scale) {
  if (scale == 1) {
    return;
  }
  std::vector<Pixel> scaled_data(data_.size() * scale * scale, {0, 0, 0});
  int scaled_row = rows_ * scale;
  int scaled_col = cols_ * scale;
  int row_ind_original = 0;
  int col_ind_original = 0;

  for (const auto &pixel : data_) {
    for (int row_ind = scale * row_ind_original;
         row_ind < scale * row_ind_original + scale; ++row_ind) {
      auto start_it =
          scaled_data.begin() + row_ind * scaled_col + scale * col_ind_original;
      auto end_it = start_it + scale;
      std::fill(start_it, end_it, pixel);
    }
    if (col_ind_original == cols_ - 1) {
      col_ind_original = 0;
      ++row_ind_original;
    } else {
      ++col_ind_original;
    }
  }
  data_ = scaled_data;
  rows_ = scaled_row;
  cols_ = scaled_col;
}

}  // namespace igg
