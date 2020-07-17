cmake_minimum_required(VERSION 3.16)
project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 14)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer -g -O1")

add_executable(leetcode_cpp main.cpp binary_tree_zigzag_level_order_traversal.cpp)