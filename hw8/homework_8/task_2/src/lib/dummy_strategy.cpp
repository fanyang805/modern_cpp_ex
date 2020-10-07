// Copyright Igor Bogoslavskyi, year 2018.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.

#include "dummy_strategy.hpp"

#include <string>

namespace igg {

bool DummyIoStrategy::Write(const std::string&, const ImageData&) const {
  return true;
}
ImageData DummyIoStrategy::Read(const std::string&) const {
  return ImageData{0, 0, 0, {{}}};
}

}  // namespace igg
