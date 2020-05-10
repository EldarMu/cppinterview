cmake_minimum_required(VERSION 3.16)

set(This cppinterview)

project(${This} CXX)

set(CMAKE_CXX_STANDARD 11)

enable_testing()

add_subdirectory(lib/googletest)

set(Headers 
	src/interviewproblems.h
)

set(Sources
	src/interviewproblems.cc
)

add_library(${This} ${Sources} ${Headers})

add_subdirectory(test)