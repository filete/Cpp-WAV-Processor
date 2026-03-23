cmake_minimum_required(VERSION 3.15)

project(wav-processor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(wav-processor
  src/main.cpp
  src/WavHeader.cpp
)

set_target_properties(wav-processor PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

target_include_directories(wav-processor
  PRIVATE include/
)
