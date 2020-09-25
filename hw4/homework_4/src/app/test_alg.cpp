#include "homework_4.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  using vector = ipb::named_vector<int>;
  vector v{"name", {8, 2, 6, 4}};
  //   ipb::clamp(v, 2, 5);
  //   for (const auto &ele : v.vector()) {
  //     std::cout << ele << std::endl;
  //   }
  ipb::reverse(v);
  ipb::print(v);
  std::cout << "----------------\n";

  return 0;
}