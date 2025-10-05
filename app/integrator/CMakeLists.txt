cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(integrator CXX)

file(
  GLOB_RECURSE MAIN_SOURCE_FILES
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  CONFIGURE_DEPENDS src/*.c*)

add_library(${PROJECT_NAME} ${MAIN_SOURCE_FILES})

# dependencies
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC fmt::fmt-header-only spdlog::spdlog_header_only)
