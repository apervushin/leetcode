cmake_minimum_required(VERSION 3.16)
project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer -g")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined -fno-sanitize-recover -g")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=integer -fno-sanitize-recover -g")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=nullability -fno-sanitize-recover -g")

add_executable(leetcode_cpp main.cpp course_schedule_iv.cpp reconstruct_itinerary.cpp redundant_connection.cpp find_the_city_with_the_smallest_number_of_neighbors_at_a_threshold_distance.cpp validate_binary_tree_nodes.cpp minimum_window_substring.cpp sliding_window_maximum.cpp unique_binary_search_trees.cpp path_sum_iii.cpp flatten_binary_tree_to_linked_list.cpp merge_two_binary_trees.cpp diameter_of_binary_tree.cpp invert_binary_tree.cpp)