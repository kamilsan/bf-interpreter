cmake_minimum_required(VERSION 2.4)
project(BF-Interpreter)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(CMAKE_CXX_STANDARD 14)

add_executable(bf
  scanner.hpp scanner.cpp
  interpreter.hpp interpreter.cpp
  main.cpp)