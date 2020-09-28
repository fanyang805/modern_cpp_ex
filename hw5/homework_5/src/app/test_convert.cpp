#include "convert_dataset.hpp"
#include "serialize.hpp"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
  const std::string img_path = "data/freiburg/images/";
  const std::string bin_path = "data/freiburg/bin/";
  ipb::serialization::sifts::ConvertDataset(img_path);

  for (const auto &entry : fs::directory_iterator(img_path)) {
    const auto &stem = entry.path().stem().string();
    const auto &extension = entry.path().extension();

    if (extension == ".png") {
      const auto &descriptors_filename = bin_path + stem + ".bin";
      if (!fs::exists(descriptors_filename)) {
        std::cerr << "[ERROR]: The binary file " << descriptors_filename
                  << " does no exists.\n";
      }
    }
  }
  // const std::string dummy_path = "data/freiburg/dummy/";
  // ipb::serialization::sifts::ConvertDataset(dummy_path);
  // std::cout << std::boolalpha << fs::is_empty(bin_path) << std::endl;

  auto descriptors = ipb::serialization::sifts::LoadDataset(bin_path);
  for (const auto &descriptor : descriptors) {
    if (descriptor.empty()) {
      std::cerr << "The descriptor is empty!\n";
    }
  }
  std::cout << "The size of vector is " << descriptors.size() << std::endl;
}