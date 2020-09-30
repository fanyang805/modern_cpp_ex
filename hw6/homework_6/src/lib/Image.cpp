#include "Image.hpp"
#include "io_tools.hpp"
#include <algorithm>

namespace igg {

// Create Image obj from .pgm file
// filename is the path of .pgm file
bool Image::FillFromPgm(const std::string &filename) {
  igg::io_tools::ImageData img_data = igg::io_tools::ReadFromPgm(filename);
  rows_ = img_data.rows;
  cols_ = img_data.cols;
  data_ = img_data.data;
  if ((img_data.data).empty()) {
    return false;
  } else {
    return true;
  }
};

// Create .pgm file from Image obj
// filename is the path of
void Image::WriteToPgm(const std::string &filename) const {
  uint8_t max_val = *(std::max_element(data_.cbegin(), data_.cend()));
  igg::io_tools::ImageData img_data{rows_, cols_, max_val, data_};
  igg::io_tools::WriteToPgm(img_data, filename);
};

// Create histogram
std::vector<float> Image::ComputeHistogram(int num_bins) const {
  std::vector<uint8_t> data_forsort{data_};
  std::sort(data_forsort.begin(), data_forsort.end());
  std::vector<float> hist(num_bins, 0.0f);

  int bin_ind = 0;
  double bin_size = 255 / double(num_bins);
  int pixel_num = 0;
  //   for (const auto &pixel : data_forsort) {
  for (std::vector<uint8_t>::const_iterator it_pixel = data_forsort.cbegin();
       it_pixel < data_forsort.cend();) {
    if (*it_pixel <= bin_size * (bin_ind + 1)) {
      ++pixel_num;
      ++it_pixel;
    } else {
      hist[bin_ind++] = float(pixel_num) / data_.size();
      pixel_num = 0;
    }
    hist[bin_ind] = float(pixel_num) / data_.size();
  }
  return hist;
};

void Image::DownScale(int scale) {
  if (scale == 1) {
    return;
  }
  std::vector<uint8_t> scaled_data(data_.size() / (scale * scale), 0);
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
  std::vector<uint8_t> scaled_data(data_.size() * scale * scale, 0);
  int scaled_row = rows_ * scale;
  int scaled_col = cols_ * scale;
  int row_ind_original = 0;
  int col_ind_original = 0;

  for (const auto &pixel : data_) {

    for (int row_ind = scale * row_ind_original;
         row_ind < scale * row_ind_original + scale; ++row_ind) {
      std::vector<uint8_t>::iterator start_it =
          scaled_data.begin() + row_ind * scaled_col + scale * col_ind_original;
      std::vector<uint8_t>::iterator end_it = start_it + scale;
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

} // namespace igg
