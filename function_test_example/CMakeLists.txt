# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(func_test VERSION 1.0.1 LANGUAGES CXX) # require C++11 set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_program(BASH_EXECUTABLE NAMES bash REQUIRED)

# add_subdirectory(source)

include_directories(${PROJECT_SOURCE_DIR}/source/sum_integers.h)
# example library
add_library(sum_integers ${PROJECT_SOURCE_DIR}/source/sum_integers.cpp)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# main code
add_executable(sum_up ${PROJECT_SOURCE_DIR}/source/main.cpp)
target_link_libraries(sum_up sum_integers)

# testing binary
add_executable(cpp_test ${PROJECT_SOURCE_DIR}/source/test.cpp)
target_link_libraries(cpp_test sum_integers)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# enable testing functionality
enable_testing()

# define tests
add_test(
  NAME bash_test
  COMMAND ${BASH_EXECUTABLE} ${PROJECT_SOURCE_DIR}/source/test.sh $<TARGET_FILE:sum_up>
  )

add_test(
  NAME cpp_test
  COMMAND $<TARGET_FILE:cpp_test>
  )
