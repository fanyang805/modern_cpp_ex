#include "convert_dataset.hpp"
#include "homework_7.h"
#include "utils.hpp"
#include <iostream>
#include <opencv2/core.hpp>

using ipb::serialization::sifts::ConvertDataset;
using ipb::serialization::sifts::LoadDataset;
using namespace ipb;
using namespace cv;

int main() {
  const int max_iter = 10;
  const int dict_size = 1000;
  auto &dictionary = ipb::BowDictionary::GetInstance();

  const auto descriptors = LoadDataset("data/freiburg/bin/");
  std::cout << descriptors.size() << std::endl;
  dictionary.set_params(max_iter, dict_size, descriptors);
  std::cout << dictionary.size() << std::endl;
  return 0;
}