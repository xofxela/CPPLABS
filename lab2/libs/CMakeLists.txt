cmake_minimum_required(VERSION 2.6)

project(filesort CXX C)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_LIB_FILE file.cpp)

set(SOURCE_LIB_SORT sort.cpp)

add_library(file STATIC ${SOURCE_LIB_FILE})

add_library(sort SHARED ${SOURCE_LIB_SORT})