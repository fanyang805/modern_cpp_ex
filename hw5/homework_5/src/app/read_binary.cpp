#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  const std::string filename{"image.dat"};
  std::ifstream readfile(filename, std::ios_base::in | std::ios_base::binary);
  if (!readfile) {
    return 1;
  }
  int aa{0};
  double bb{0};
  std::vector<int> vec(5, 0);
  readfile.read(reinterpret_cast<char *>(&aa), sizeof(aa));
  readfile.read(reinterpret_cast<char *>(&bb), sizeof(bb));
  readfile.read(reinterpret_cast<char *>(&vec.front()),
                vec.size() * sizeof(int));

  std::cout << "The value of a is " << aa << std::endl;
  std::cout << "The value of b is " << bb << std::endl;
  std::cout << "The element of vec is: ";
  for (const int &ele : vec) {
    std::cout << ele << " ";
  }
  std::cout << std::endl;

  return 0;
}