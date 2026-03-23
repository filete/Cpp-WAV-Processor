cmake_minimum_required(VERSION 3.15)

project(wav-processor)

set(CMAKE_CXX_STANDARD 17)

add_executable(wav-processor
  src/main.cpp
)

target_include_directories(wav-processor
  PRIVATE include/
)
