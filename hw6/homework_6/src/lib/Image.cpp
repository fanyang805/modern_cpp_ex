#include "Image.hpp"
#include "io_tools.hpp"
#include <algorithm>

// Create Image obj from .pgm file
// filename is the path of .pgm file
bool Image::FillFromPgm(const std::string &filename) {
  igg::io_tools::ImageData img_data = igg::io_tools::ReadFromPgm(filename);
  rows_ = img_data.rows;
  cols_ = img_data.cols;
  max_val_ = img_data.max_val;
  data_ = img_data.data;
  if ((img_data.data).empty()) {
    return false;
  } else {
    return true;
  }
};

// Create .pgm file from Image obj
// filename is the path of
void Image::WriteToPgm(const std::string &filename) {
  igg::io_tools::ImageData img_data{rows_, cols_, max_val_, data_};
  igg::io_tools::WriteToPgm(img_data, filename);
};

// Create histogram
std::vector<float> Image::ComputeHistogram(int num_bins) const {
  std::vector<uint8_t> data_forsort{data_};
  std::sort(data_forsort.begin(), data_forsort.end());
  std::vector<float> hist(num_bins, 0.0f);

  unsigned bin_ind = 0;
  double bin_size = 255 / double(num_bins);
  unsigned pixel_num = 0;
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
}
