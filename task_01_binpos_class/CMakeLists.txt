cmake_minimum_required(VERSION 3.16.0)
project(binops VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)

add_executable(binop main.cpp binop.cpp)
