#include "homework_4.h"
#include <boost/core/demangle.hpp>
#include <iostream>
#include <vector>

int main() {
  //   const int kNumElements = 5;
  const std::string empty_str;
  const std::vector<int> std_empty_vector{};
  //   const std::vector<int> std_vector(kNumElements);

  ipb::named_vector<int> templated_vector;
  std::cout << std::boolalpha << templated_vector.empty() << std::endl;
  std::cout << std::boolalpha << templated_vector.name().empty() << std::endl;
  std::cout << std::boolalpha << templated_vector.vector().empty() << std::endl;
  if (templated_vector.name() == empty_str) {
    std::cout << std::boolalpha << true << std::endl;
  }
  if (templated_vector.vector() == std_empty_vector) {
    std::cout << std::boolalpha << true << std::endl;
  }

  return 0;
}