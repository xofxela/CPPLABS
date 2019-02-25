cmake_minimum_required (VERSION 2.6) 
 
set (PROJECT hello_world) 
 
project (${PROJECT}) 
 
set (HEADERS 
	file.h
	main.h)
 
set (SOURCES 
	file.cpp
	main.cpp) 
 
add_executable (${PROJECT} ${HEADERS} ${SOURCES})
