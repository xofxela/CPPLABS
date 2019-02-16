cmake_minimum_required(VERSION 3.14)
project(cmake_test)

set(SRC_EXE main.cpp)
set(SRC_LIB file.cpp)

add_library(main STATIC ${SRC_LIB})
add_executable(main ${SRC_EXE})

target_link_libraries(main main)