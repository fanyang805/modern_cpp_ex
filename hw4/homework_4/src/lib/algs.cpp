#include "homework_4.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

namespace ipb {

int accumulate(const named_vector<int> &para_vec) {
  const std::vector<int> &vct = para_vec.vector();
  return std::accumulate(vct.cbegin(), vct.cend(), 0);
}

int count(const named_vector<int> &para_vec, const int &para_obj) {
  const std::vector<int> &vec = para_vec.vector();
  return std::count(vec.cbegin(), vec.cend(), para_obj);
}

inline bool even(int i) { return i % 2 == 0; }
bool all_even(const named_vector<int> &para_vec) {
  const std::vector<int> &vec = para_vec.vector();
  return std::all_of(vec.cbegin(), vec.cend(), even);
}

void clamp(named_vector<int> &para_vec, const int kMin, const int kMax) {

  auto value = [kMin, kMax](int &ele) { ele = std::clamp(ele, kMin, kMax); };
  std::vector<int> &vec = para_vec.vector();
  std::for_each(vec.begin(), vec.end(), value);
}

void fill(named_vector<int> &para_vec, const int &para_obj) {
  std::fill(para_vec.vector().begin(), para_vec.vector().end(), para_obj);
}

bool find(const named_vector<int> &para_vec, const int &para_obj) {
  const std::vector<int> &vec = para_vec.vector();
  return std::find(vec.cbegin(), vec.cend(), para_obj) != vec.cend();
}

void print(const named_vector<int> &para_vec) {
  std::cout << para_vec.name() << " ";
  for (const int &ele : para_vec.vector()) {
    std::cout << ele << " ";
  }
  std::cout << std::endl;
}

auto UpperCase(char c) { return std::toupper(c); }
void toupper(named_vector<int> &para_vec) {
  std::string &name = para_vec.name();
  std::transform(name.begin(), name.end(), name.begin(), UpperCase);
}

void sort(named_vector<int> &para_vec) {
  std::vector<int> &vec = para_vec.vector();
  std::sort(vec.begin(), vec.end());
}

void rotate(named_vector<int> &para_vec, const int num) {
  std::vector<int> &vec = para_vec.vector();
  std::rotate(vec.begin(), vec.begin() + num, vec.end());
}

void reverse(named_vector<int> &para_vec) {
  std::vector<int> &vec = para_vec.vector();
  std::reverse(vec.begin(), vec.end());
}

} // namespace ipb