cmake_minimum_required(VERSION 3.27.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Project Info
project(program)

set(CMAKE_CXX_STANDARD 20)

# Add the source files for the project
file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.h)

# Add the executable target for the project
add_executable(program ${SOURCE_FILES})

# suppress generation of ZERO_CHECK:
set(CMAKE_SUPPRESS_REGENERATION true)
