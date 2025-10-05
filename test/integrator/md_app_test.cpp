#include <gtest/gtest.h>
#include <spdlog/spdlog.h>

#include <md_app.hpp>
#include <memory>
#include <thread>

namespace md_fp32 {
namespace integrator {

class DummyIntegrator1 : public Integrator {
 public:
  MdStatus Init() override {
    spdlog::info("{}::{}() completed", Name(), __func__);
    return MdStatus::SUCCESS;
  }

  MdStatus Term() override {
    spdlog::info("{}::{}() completed", Name(), __func__);
    return MdStatus::SUCCESS;
  }

  MdStatus Run() override {
    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    spdlog::info("{}::{}() completed", Name(), __func__);
    return MdStatus::SUCCESS;
  }

  const char* Name() const override { return "Dummy1"; }
  std::string Dump() override { return std::string(""); }
};

class DummyIntegrator2 : public Integrator {
 public:
  MdStatus Init() override {
    spdlog::info("{}::{}() completed", Name(), __func__);
    return MdStatus::SUCCESS;
  }

  MdStatus Term() override {
    spdlog::info("{}::{}() completed", Name(), __func__);
    return MdStatus::SUCCESS;
  }

  MdStatus Run() override {
    std::this_thread::sleep_for(std::chrono::milliseconds(2));
    spdlog::info("{}::{}() completed", Name(), __func__);
    return MdStatus::SUCCESS;
  }

  const char* Name() const override { return "Dummy2"; }
  std::string Dump() override { return std::string(""); }
};

TEST(md_app_test, MdApp_Init_Term_normal) {
  auto md_app = std::make_unique<MdApp>();

  md_app->AddIntegrator(std::make_unique<DummyIntegrator1>());
  md_app->AddIntegrator(std::make_unique<DummyIntegrator2>());

  ASSERT_EQ(md_app->Init(), MdStatus::SUCCESS);
  EXPECT_EQ(md_app->Term(), MdStatus::SUCCESS);
}

TEST(md_app_test, MdApp_Run_normal) {
  auto md_app = std::make_unique<MdApp>();

  md_app->AddIntegrator(std::make_unique<DummyIntegrator1>());
  md_app->AddIntegrator(std::make_unique<DummyIntegrator2>());

  ASSERT_EQ(md_app->Init(), MdStatus::SUCCESS);
  EXPECT_EQ(md_app->Run(), MdStatus::SUCCESS);
  ASSERT_EQ(md_app->Term(), MdStatus::SUCCESS);
}

TEST(md_app_test, MdApp_Name_normal) {
  auto md_app = std::make_unique<MdApp>();

  EXPECT_STREQ(md_app->Name(), "MdApp");
}

TEST(md_app_test, MdApp_Dump_normal) {
  auto md_app = std::make_unique<MdApp>();

  md_app->AddIntegrator(std::make_unique<DummyIntegrator1>());
  md_app->AddIntegrator(std::make_unique<DummyIntegrator2>());
  md_app->AddIntegrator(std::make_unique<DummyIntegrator1>());

  const auto expected = std::string(R"(name: MdApp
modules:
  - Dummy1
  - Dummy2
  - Dummy1
)");

  EXPECT_EQ(md_app->Dump(), expected);
}

}  // namespace integrator
}  // namespace md_fp32
