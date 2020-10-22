#include <iostream>
#include <string>
#include <vector>

#include "bowdictionary.hpp"
#include "convert_dataset.hpp"
#include "histogram.hpp"
#include "serialize.hpp"
#include "utils.hpp"

using namespace bovw;

int main() {

  // Compute histograms
  std::vector<bovw::Histogram> vec_hist_from_csv =
      bovw::gen_vechist_from_csv("Histogram.csv");
  std::cout << vec_hist_from_csv.size() << std::endl;
  for (auto &hist : vec_hist_from_csv) {
    // std::cout << "empty: " << std::boolalpha << hist.empty() << std::endl;
    std::cout << hist << std::endl;
  }

  // Build dictionary
  const std::string &bin_path{"data/bin/"};
  const std::string &bin_extension{".bin"};
  std::vector<std::string> bin_sequence =
      bovw::get_sequence(bin_path, bin_extension, 0, 9);
  std::cout << "Start to read binary files.\n";
  std::vector<cv::Mat> descriptors =
      bovw::serialization::sifts::LoadDataset("data/bin/", bin_sequence, 12);
  std::cout << "descriptors vector size: " << descriptors.size() << std::endl;
  std::cout << "Start to create dictionary.\n";
  auto &dictionary = bovw::BowDictionary::GetInstance();
  dictionary.build(100, 100, descriptors);
  dictionary.set_words_ocurrence(vec_hist_from_csv);
  for (const auto &word_num : dictionary.words_occurrence()) {
    std::cout << word_num << ", ";
  }
  std::cout << std::endl;

  const std::string filename_reweighted{"Reweighted_histogram.csv"};
  for (auto &hist : vec_hist_from_csv) {
    // auto &hist = vec_hist_from_csv[3];

    hist.set_img_num(10);
    hist.reweight_hist(dictionary);
    std::vector<float> data = hist.reweighted_data();
    std::cout << data << std::endl;
    hist.WriteToCSV(filename_reweighted, true);
  }
  return 0;
} // namespace )
