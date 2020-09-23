#include "image_browser.hpp"
// #include <chrono>
#include <cstdlib>
#include <ctime>
#include <string>
// #include <thread>

int rand_num(int min, int max) {
  // std::chrono::seconds dura(1);
  // std::this_thread::sleep_for(dura);
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  static constexpr double fraction{1.0 / (RAND_MAX + 1.0)};
  return min + (max - min + 1) * (std::rand() * fraction);
}

int main() {
  std::string title = "Fan's Image Browser";
  std::string stylesheet = "./web_app/style.css";
  std::vector<image_browser::ImageRow> rows;
  for (int row_num = 0; row_num < 3; ++row_num) {
    std::vector<image_browser::ScoredImage> img_row_vec;
    for (int col_num = 0; col_num < 3; ++col_num) {
      int img_id = row_num * 3 + col_num;
      std::string img_path =
          "./web_app/data/000" + std::to_string(img_id) + "00.png";
      double score = rand_num(0, 100) * 0.01;
      img_row_vec.push_back(image_browser::ScoredImage{img_path, score});
    }
    image_browser::ImageRow img_row = {img_row_vec[0], img_row_vec[1],
                                       img_row_vec[2]};
    rows.push_back(img_row);
  }
  image_browser::CreateImageBrowser(title, stylesheet, rows);
  return 0;
}