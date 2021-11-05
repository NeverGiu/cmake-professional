cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(myApp VERSION 1.0.0 LANGUAGES CXX)

# message(STATUS "Top: CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
# message(STATUS "Top: CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")
# message(STATUS "Top: CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")
# message(STATUS "Top: CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR}")
# set(myVar foo)
# message(STATUS "Parent (before): myVar = ${myVar}")

add_subdirectory(src)
# message(STATUS "Parent (before): myVar = ${myVar}")
message(STATUS "===================================")
include(src/CMakeLists.txt)

# message(STATUS "Top: CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")
# message(STATUS "Top: CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR}")
# message(STATUS "Parent (after): myVar = ${myVar}")
# message(STATUS "Parent (after): childVar = ${childVar}")
