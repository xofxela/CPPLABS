cmake_minimum_required(VERSION 2.6)
 
project(filesort CXX C)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_EXE main.cpp)

#link_directories(libs)
	
include_directories(libs)

add_subdirectory(libs)

add_executable(filesort ${SOURCE_EXE})

target_link_libraries(filesort PUBLIC file)

target_link_libraries(filesort PUBLIC sort)