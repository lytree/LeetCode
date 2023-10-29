cmake_minimum_required(VERSION 3.20)
project(LeetCode VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)


find_package(fmt CONFIG REQUIRED)

add_executable(LeetCode main.cpp)
add_executable(all_2 src/all/2.cpp)
add_executable(all_3 src/all/3.cpp)

target_link_libraries(all_2 PRIVATE fmt::fmt)
target_link_libraries(all_3 PRIVATE fmt::fmt)
target_link_libraries(LeetCode PRIVATE fmt::fmt)


