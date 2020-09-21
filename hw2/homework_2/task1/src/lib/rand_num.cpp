#include "rand_num.hpp"
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <thread>

int rand_num(int min, int max) {
  std::chrono::seconds dura(1);
  std::this_thread::sleep_for(dura);
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  static constexpr double fraction{1.0 / (RAND_MAX + 1.0)};
  return min + (max - min + 1) * (std::rand() * fraction);
}