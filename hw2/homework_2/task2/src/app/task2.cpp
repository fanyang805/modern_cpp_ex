#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {

  if (argc != 3) {
    std::cerr << "The number of inputs should be two. Error encountered, "
                 "exiting...\n";
    return 1;
  }

  std::vector<std::stringstream> vec_ss(argv + 1, argv + argc);
  std::vector<int> vec_num{0, 0};
  std::vector<std::string> vec_ext(2);
  int cnt = 0;

  for (std::stringstream &ss : vec_ss) {
    if (!(ss >> vec_num[cnt])) {
      std::cerr << "The name should be number. Error encountered, exiting...\n";
      return 1;
    }
    if (!(ss >> vec_ext[cnt])) {
      std::cerr
          << "The extension should be string. Error encountered, exiting...\n";
      return 1;
    }
    ++cnt;
  }

  double output_num = -1.0;
  if (vec_ext[0] + vec_ext[1] == ".txt.txt") {
    output_num = (vec_num[0] + vec_num[1]) / 2;
  } else if (vec_ext[0] + vec_ext[1] == ".png.png") {
    output_num = vec_num[0] + vec_num[1];
  } else if (vec_ext[0] + vec_ext[1] == ".txt.png") {
    output_num = vec_num[0] % vec_num[1];
  } else {
    std::cerr << "Invalid extensions!\n";
    return 1;
  }
  //   std::cout << "The output is " << output_num << std::endl;
  std::cout << output_num << std::endl;

  return 0;
}