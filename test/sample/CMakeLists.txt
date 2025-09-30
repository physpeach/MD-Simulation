cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(gtest_sample CXX)

file(
  GLOB_RECURSE MAIN_SOURCE_FILES
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  CONFIGURE_DEPENDS *.c*)

add_executable(${PROJECT_NAME} ${MAIN_SOURCE_FILES})

# dependencies
find_package(GTest CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest GTest::gtest_main)

add_test(NAME ${PROJECT_NAME}
    COMMAND ${CMAKE_BINARY_DIR}/$<CONFIG>/bin/${PROJECT_NAME}
)
