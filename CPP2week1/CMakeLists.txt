cmake_minimum_required(VERSION 2.6)
project (Test)
# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

add_definitions(-std=c++11)

file(GLOB SRC . *.cpp *.h)

include_directories("${PROJECT_BINARY_DIR}")

set( EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/build" )

add_executable(Test Text.cpp main.cpp Text.h)
