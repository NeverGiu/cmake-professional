cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(check-lib VERSION 1.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(source)
