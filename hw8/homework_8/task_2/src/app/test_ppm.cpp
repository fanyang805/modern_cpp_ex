#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

#include "homework_8.h"
#include "strategy.hpp"

using namespace igg;

int main() {
  Image img;
  ImageData img_data;

  img.SetIoStrategy(std::make_shared<PpmIoStrategy>());
  const std::string& file_name = "data/pbmlib.ascii.ppm";
  img.ReadFromDisk(file_name);
  img.WriteToDisk("pbm_test.ppm");

  return 0;
}