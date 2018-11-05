cmake_minimum_required(VERSION 3.12)
project(themaze)

set(CMAKE_CXX_STANDARD 17)

add_executable(themaze main.cpp include/catch2/catch.hpp definitions.h include/json11/json11.cpp include/json11/json11.hpp)