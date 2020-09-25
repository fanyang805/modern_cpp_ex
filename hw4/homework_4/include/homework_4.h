#ifndef HOMEWORK_4_H_
#define HOMEWORK_4_H_

#include <string>
#include <vector>

namespace ipb {

template <class T> class named_vector {
private:
  std::string my_name;
  std::vector<T> my_vector;

public:
  // constructor
  named_vector() = default;
  named_vector(const std::string &para_name, const std::vector<T> &para_vec)
      : my_name{para_name}, my_vector{para_vec} {}
  // member functions
  bool empty() { return my_name.empty() || my_vector.empty(); };
  std::string name() { return my_name; };
  std::vector<T> vector() { return my_vector; };
  size_t size() { return my_name.size() + my_vector.size(); };
  size_t capacity() { return my_vector.capacity(); };
  void resize(size_t size_num) { my_vector.resize(size_num); };
  void reserve(size_t cap_num) { my_vector.reserve(cap_num); };
};

} // namespace ipb

#endif