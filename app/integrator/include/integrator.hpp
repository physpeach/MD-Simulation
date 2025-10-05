#pragma once

#include <string>

namespace md_fp32 {
namespace integrator {

enum class MdStatus { SUCCESS, WARNING, ERROR };

class Integrator {
 public:
  virtual ~Integrator(){};
  virtual MdStatus Init() = 0;
  virtual MdStatus Term() = 0;
  virtual MdStatus Run() = 0;

  virtual const char* Name() const = 0;
  virtual std::string Dump() = 0;
};

}  // namespace integrator
}  // namespace md_fp32
