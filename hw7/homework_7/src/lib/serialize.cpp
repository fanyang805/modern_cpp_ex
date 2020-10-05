#include "serialize.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <opencv2/core/mat.hpp>
#include <string>

namespace ipb::serialization {

void Serialize(const cv::Mat &m, const std::string &filename) {
  namespace fs = std::filesystem;
  uchar *ptmat = m.data;
  int row_num = m.rows;
  int col_num = m.cols;
  int type_int = m.type();

  // Get the filename without path
  fs::create_directories(fs::path(filename).remove_filename());
  std::ofstream write_bin(filename, std::ios_base::out | std::ios_base::binary);

  // Use size_t num_byte = m.step[0] * m.rows for more general case
  // Write the dimension of the Mat
  write_bin.write(reinterpret_cast<char *>(&row_num), sizeof(int));
  write_bin.write(reinterpret_cast<char *>(&col_num), sizeof(int));
  write_bin.write(reinterpret_cast<char *>(&type_int), sizeof(int));
  write_bin.write(reinterpret_cast<char *>(ptmat), m.total() * m.elemSize());
  // write_bin.write(reinterpret_cast<char *>(m_cp.ptr(0)),
  //                 m.total() * m.elemSize());
  write_bin.close();
}

cv::Mat Deserialize(const std::string &filename) {
  int row_num, col_num, type_int;

  std::ifstream read_bin(filename, std::ios_base::in | std::ios_base::binary);

  read_bin.read(reinterpret_cast<char *>(&row_num), sizeof(int));
  read_bin.read(reinterpret_cast<char *>(&col_num), sizeof(int));
  read_bin.read(reinterpret_cast<char *>(&type_int), sizeof(int));
  // std::cout << row_num << " " << col_num << std::endl;
  cv::Mat filem = cv::Mat::zeros(row_num, col_num, type_int);
  read_bin.read(reinterpret_cast<char *>(filem.data),
                filem.total() * filem.elemSize());
  return filem;
}

} // namespace ipb::serialization