cmake_minimum_required(VERSION 3.12)
project(Ass1Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ass1Project main.cpp ppm/ppm.cpp Image.cpp Image.h Color.cpp)