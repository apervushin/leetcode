cmake_minimum_required(VERSION 3.16)
project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 14)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer -g -O1")

add_executable(leetcode_cpp main.cpp powx_n.cpp rotate_image.cpp sort_colors.cpp top_k_frequent_elements.cpp climbing_stairs.cpp binary_tree_inorder_traversal.cpp symmetric_tree.cpp best_time_to_buy_and_sell_stock.cpp reverse_linked_list.cpp binary_tree_level_order_traversal.cpp flatten_nested_list_iterator.cpp nested_integer.cpp set_matrix_zeroes.cpp min_stack.cpp)