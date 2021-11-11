cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(sup-config-cdash VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

enable_testing()

include(CTest)

add_subdirectory(tests)
