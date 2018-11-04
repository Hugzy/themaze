cmake_minimum_required(VERSION 3.12)
project(themaze)

set(CMAKE_CXX_STANDARD 17)

add_executable(themaze main.cpp vendors/catch2/catch.hpp test_main.h maze_main.cpp maze_main.h)