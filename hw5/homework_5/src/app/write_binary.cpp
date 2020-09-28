#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int a = 1;
  double b = 8.8;
  std::vector<int> vec_int{1, 2, 3, 4, 5};
  const std::string filename{"data/image.dat"};
  std::ofstream writefile(filename, std::ios_base::out | std::ios_base::binary);
  writefile.write(reinterpret_cast<char *>(&a), sizeof(a));
  writefile.write(reinterpret_cast<char *>(&b), sizeof(b));
  writefile.write(reinterpret_cast<char *>(&vec_int.front()),
                  vec_int.size() * sizeof(int));
  return 0;
}