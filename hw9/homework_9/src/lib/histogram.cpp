#include "histogram.hpp"

#include <fstream>

#include "bowdictionary.hpp"
#include "sstream"
#include "utils.hpp"

using namespace cv;

namespace ipb {

Histogram::Histogram(cv::Mat descriptors, const BowDictionary &dictionary) {
  Mat vocabularies = dictionary.vocabulary();
  if (descriptors.empty() || dictionary.empty()) {
    std::cerr << "The inputs of histogram are empty!\n";
    return;
  }
  data_ = std::vector<int>(vocabularies.rows);
  for (int des_id = 0; des_id < descriptors.rows; ++des_id) {
    double min_distance = INT_MAX;
    int min_voc_id = -1;
    for (int voc_id = 0; voc_id < vocabularies.rows; ++voc_id) {
      double distance = euclidean_dis_sq<float>(descriptors.row(des_id),
                                                vocabularies.row(voc_id));
      if (min_distance > distance) {
        min_distance = distance;
        min_voc_id = voc_id;
      }
    }
    ++data_[min_voc_id];
    // std::cout << min_voc_id << std::endl;
  }
}

Histogram Histogram::ReadFromCSV(const std::string &filename) {
  std::vector<int> data;
  std::ifstream in(filename, std::ios_base::in);
  if (!in) {
    std::cerr << "Cannot read .csv file: " << filename << std::endl;
    exit(-1);
  }

  std::string line;
  while (std::getline(in, line)) {
    std::stringstream ss{line};
    // int counts = -1;
    std::string str_counts;
    while (std::getline(ss, str_counts, ',')) {
      int counts = std::stoi(str_counts);
      data.emplace_back(counts);
    }
  }

  return Histogram(data);
}

void Histogram::WriteToCSV(const std::string &filename) const {
  std::ofstream out(filename);
  size_t counts = 1;
  for (const int &voc : data_) {
    out << voc;
    if (counts++ < data_.size()) {
      out << ",";
    }
  }
}

std::ostream &operator<<(std::ostream &os, const Histogram &hist_obj) {
  for (const int &voc : hist_obj.data_) {
    os << voc << ", ";
  }
  return os;
}

}  // namespace ipb