cmake_minimum_required(VERSION 3.16)

include(Dart)

set(This cppinterview_tests)

set(Sources
	interviewproblems_test.cc
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
	gtest_main
	gmock_main
	cppinterview
)

add_test(
	NAME ${This}
	COMMAND ${This}
)