cmake_minimum_required(VERSION 2.6)

project(test CXX C)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_EXE test_main.cpp)
	
include_directories(
libs
${GTEST_INCLUDE_DIRS}
)

add_executable(test ${SOURCE_EXE})

target_link_libraries(test ${GTEST_LIBRARIES} sort)

enable_testing()
