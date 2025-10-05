#include <md_app.hpp>
#include <memory>

int main() {
  auto md_app = std::make_unique<md_fp32::integrator::MdApp>();

  if (md_app->Init() == md_fp32::integrator::MdStatus::ERROR) {
    return -1;
  }

  if (md_app->Run() == md_fp32::integrator::MdStatus::ERROR) {
    return -1;
  }

  if (md_app->Term() == md_fp32::integrator::MdStatus::ERROR) {
    return -1;
  }

  return 0;
}
