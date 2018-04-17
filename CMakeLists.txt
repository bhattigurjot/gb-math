cmake_minimum_required(VERSION 3.9.2)

project(gb-math)

include_directories(include)

file(GLOB SOURCES "tests/*.cpp")

add_executable(gb-math-tests ${SOURCES})