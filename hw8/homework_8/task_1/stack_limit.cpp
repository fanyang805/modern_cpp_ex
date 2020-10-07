#include <algorithm>
#include <cstddef>
#include <iostream>
#include <math.h>
#include <vector>

int main() {
  size_t one_hundred_KB = 102400;
  size_t counter = 1;

  while (true) {
    std::byte byte_arr[one_hundred_KB * counter];
    std::fill(byte_arr, byte_arr + one_hundred_KB * counter, std::byte(24));
    std::cerr << 100 * counter++ << "[KiB] Allocated in the stack\n";
  }

  return 0;
}