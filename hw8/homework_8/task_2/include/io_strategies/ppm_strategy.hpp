#ifndef PPM_STRATEGY_HPP_
#define PPM_STRATEGY_HPP_

#include "strategy.hpp"

namespace igg {

class PpmIoStrategy : public IoStrategy {
 public:
  bool Write(const std::string& file_name,
             const ImageData& data) const override;
  ImageData Read(const std::string& file_name) const override;
};

}  // namespace igg

#endif