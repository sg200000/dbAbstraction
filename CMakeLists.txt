cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 20)

project(dbAbstraction VERSION 1.0)

add_executable(main main.cpp)
target_include_directories(main PUBLIC inc/)
