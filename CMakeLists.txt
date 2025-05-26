cmake_minimum_required(VERSION 2.4)
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(cpp-lib LANGUAGES CXX)
add_executable(test
  io.cpp
  io.h
  json.cpp
  json.h
  misc.cpp
  misc.h
  time.cpp
  time.h
  test.cpp
)
