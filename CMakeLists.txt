cmake_minimum_required(VERSION 3.14)

project(demo CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main main.cc)

find_package(folly CONFIG REQUIRED)

target_link_libraries(main PRIVATE
Folly::folly
Folly::folly_deps
Folly::follybenchmark
Folly::folly_test_util)
