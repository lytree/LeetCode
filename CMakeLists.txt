cmake_minimum_required(VERSION 3.20)
project(LeetCode VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)


find_package(fmt CONFIG REQUIRED)

add_executable(LeetCode main.cpp)
add_executable(all_1 src/all/1.cpp)
add_executable(all_2 src/all/2.cpp)
add_executable(all_3 src/all/3.cpp)
add_executable(all_12 src/all/12.cpp)
add_executable(all_13 src/all/13.cpp)
add_executable(all_94 src/all/94.cpp)
add_executable(all_95 src/all/95.cpp)
add_executable(all_96 src/all/96.cpp)
# target_link_libraries(all_2 PRIVATE fmt::fmt)
# target_link_libraries(all_3 PRIVATE fmt::fmt)
# target_link_libraries(all_12 PRIVATE fmt::fmt)
# target_link_libraries(all_13 PRIVATE fmt::fmt)
# target_link_libraries(LeetCode PRIVATE fmt::fmt)


