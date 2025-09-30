cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(spdlog_experimentals CXX)

file(
  GLOB_RECURSE MAIN_SOURCE_FILES
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  CONFIGURE_DEPENDS *.c*)

add_executable(${PROJECT_NAME} ${MAIN_SOURCE_FILES})

# dependencies
find_package(spdlog CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog_header_only)
