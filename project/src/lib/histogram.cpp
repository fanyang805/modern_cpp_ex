#include "histogram.hpp"

#include <fstream>
#include <limits>
#include <sstream>

#include "bowdictionary.hpp"
#include "utils.hpp"

using namespace cv;

namespace bovw {

Histogram::Histogram(cv::Mat descriptors, const BowDictionary &dictionary) {
  Mat vocabularies = dictionary.vocabulary();
  if (descriptors.empty() || dictionary.empty()) {
    std::cerr << "The inputs of histogram are empty!\n";
    return;
  }
  data_ = std::vector<int>(vocabularies.rows);
  for (int des_id = 0; des_id < descriptors.rows; ++des_id) {
    float min_distance = std::numeric_limits<float>::max();
    int min_voc_id = -1;
    for (int voc_id = 0; voc_id < vocabularies.rows; ++voc_id) {
      float distance =
          euclidean_dis_sq(descriptors.row(des_id), vocabularies.row(voc_id));
      if (min_distance > distance) {
        min_distance = distance;
        min_voc_id = voc_id;
      }
    }
    ++data_[min_voc_id];
  }
}

Histogram::Histogram(const cv::Mat_<int> &bestLabel, int dictionary_size) {
  data_ = std::vector<int>(dictionary_size);
  for (const auto &word_idx : bestLabel) {
    ++data_[word_idx];
  }
}

void Histogram::ReadFromCSV(const std::string &filename) {
  std::vector<int> data;
  std::ifstream in(filename, std::ios_base::in);
  if (!in) {
    std::cerr << "Cannot read .csv file: " << filename << std::endl;
    return;
  }

  std::string line;
  // while (std::getline(in, line)) {
  std::getline(in, line);
  // std::cout << line << std::endl;
  std::stringstream ss{line};
  std::string str_counts;
  while (std::getline(ss, str_counts, ',')) {
    int counts = std::stoi(str_counts);
    data.emplace_back(counts);
    // std::cout << counts << " ";
  }
  // std::cout << std::endl;
  // }
  // std::cout << data.size() << std::endl;

  data_ = data;
  return;
}

void Histogram::WriteToCSV(const std::string &filename) const {
  std::ofstream out(filename, std::ios::app);
  size_t counts = 1;
  for (const int &voc : data_) {
    out << voc;
    if (counts++ < data_.size()) {
      out << ",";
    }
  }
  out << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Histogram &hist_obj) {
  size_t counts = 1;
  for (const int &voc : hist_obj.data_) {
    os << voc;
    if (counts++ < hist_obj.data_.size()) {
      os << ",";
    }
  }
  return os;
}

} // namespace bovw