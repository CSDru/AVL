cmake_minimum_required(VERSION 3.24)
project(AVL)

set(CMAKE_CXX_STANDARD 17)

add_executable(AVL main.cpp Node.h AVL.h AVL.cpp)
