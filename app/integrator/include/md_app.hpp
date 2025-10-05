#pragma once

#include <integrator.hpp>
#include <memory>
#include <vector>

namespace md_fp32 {
namespace integrator {

class MdApp : public Integrator {
 public:
  MdStatus Init() override;
  MdStatus Term() override;
  MdStatus Run() override;

  const char* Name() const override;
  std::string Dump() override;

  void AddIntegrator(std::unique_ptr<Integrator> integrator);

 private:
  const char* name_ = "MdApp";
  std::vector<std::unique_ptr<Integrator>> integrator_;
};

}  // namespace integrator
}  // namespace md_fp32
