#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <chrono>
#include <cstdint>
#include <md_app.hpp>

namespace md_fp32 {
namespace integrator {

MdStatus MdApp::Init() {
  const auto kStartTime = std::chrono::system_clock::now();

  for (auto& i : integrator_) {
    if (i->Init() == MdStatus::ERROR) {
      spdlog::error("{}::{}() error at module = {}", Name(), __func__,
                    i->Name());
      return MdStatus::ERROR;
    }
  }

  const auto kEndTime = std::chrono::system_clock::now();
  int64_t kDuration = std::chrono::duration_cast<std::chrono::milliseconds>(
                          kEndTime - kStartTime)
                          .count();

  spdlog::info("{}::{}() completed in {} [ms]", Name(), __func__, kDuration);
  return MdStatus::SUCCESS;
}

MdStatus MdApp::Term() {
  const auto kStartTime = std::chrono::system_clock::now();

  for (auto& i : integrator_) {
    if (i->Term() == MdStatus::ERROR) {
      return MdStatus::ERROR;
    }
  }

  const auto kEndTime = std::chrono::system_clock::now();
  const int64_t kDuration =
      std::chrono::duration_cast<std::chrono::milliseconds>(kEndTime -
                                                            kStartTime)
          .count();

  spdlog::info("{}::{}() completed in {} [ms]", Name(), __func__, kDuration);
  return MdStatus::SUCCESS;
}

MdStatus MdApp::Run() {
  const auto kStartTime = std::chrono::system_clock::now();

  for (auto& i : integrator_) {
    if (i->Run() == MdStatus::ERROR) {
      spdlog::error("{}::{}() error at module = {}", Name(), __func__,
                    i->Name());
      return MdStatus::ERROR;
    }
  }

  const auto kEndTime = std::chrono::system_clock::now();
  const int64_t kDuration =
      std::chrono::duration_cast<std::chrono::milliseconds>(kEndTime -
                                                            kStartTime)
          .count();

  spdlog::info("{}::{}() completed in {} [ms]", Name(), __func__, kDuration);
  return MdStatus::SUCCESS;
}

const char* MdApp::Name() const { return name_; }

std::string MdApp::Dump() {
  std::string dump_str = fmt::format("name: {}\nmodules:\n", Name());
  for (const auto& i : integrator_) {
    dump_str += fmt::format("  - {}\n", i->Name());
  }
  return dump_str;
}

void MdApp::AddIntegrator(std::unique_ptr<Integrator> integrator) {
  integrator_.push_back(std::move(integrator));
}

}  // namespace integrator
}  // namespace md_fp32
