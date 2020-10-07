#include "ppm_strategy.hpp"

#include <fstream>
#include <sstream>

namespace igg {

bool PpmIoStrategy::Write(const std::string& file_name,
                          const ImageData& data) const {
  std::ofstream out(file_name, std::ios_base::out);

  if (!out) {
    return false;
  }

  out << "P3\n"
      << data.rows << " " << data.cols << std::endl
      << static_cast<int>(data.max_val) << std::endl;
  for (int r = 0; r < data.rows; ++r) {
    for (int c = 0; c < data.cols; ++c) {
      int idx = r * data.cols + c;
      out << static_cast<int>(data.data[0][idx]) << " "
          << static_cast<int>(data.data[1][idx]) << " "
          << static_cast<int>(data.data[2][idx]) << " ";
    }
    out << std::endl;
  }

  return true;
};

ImageData PpmIoStrategy::Read(const std::string& file_name) const {
  std::ifstream in(file_name, std::ios_base::in);
  std::stringstream ss;
  if (!in) {
    return {0, 0, 0, {}};
  }

  int rows = 0;
  int cols = 0;
  int max_val = 0;
  std::string type;
  std::string line;
  // std::vector<std::vector<uint8_t>> data;

  // Delete all comment lines, store other to stringstream
  while (std::getline(in, line)) {
    if (line[0] != '#') {
      ss << line << "\n";
    }
  };

  ss >> type >> rows >> cols >> max_val;

  std::vector<uint8_t> red(rows * cols, 0);
  std::vector<uint8_t> green(rows * cols, 0);
  std::vector<uint8_t> blue(rows * cols, 0);
  int red_int, green_int, blue_int;

  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      int idx = r * cols + c;
      ss >> red_int >> green_int >> blue_int;
      red[idx] = static_cast<uint8_t>(red_int);
      green[idx] = static_cast<uint8_t>(green_int);
      blue[idx] = static_cast<uint8_t>(blue_int);
    }
  }
  return {rows, cols, static_cast<uint8_t>(max_val), {red, green, blue}};
}

}  // namespace igg