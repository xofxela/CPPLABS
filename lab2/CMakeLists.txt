cmake_minimum_required(VERSION 2.8.2)
project(test CXX C)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_definitions(-Dgtest_disable_pthreads=ON)
include_directories(libs)
add_subdirectory(libs)
add_subdirectory(test)
add_subdirectory(googletest-master)