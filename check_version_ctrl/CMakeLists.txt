cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
include(projectVersionDetails.cmake)
project(FooBar VERSION ${FooBar_VER} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# add_subdirectory(source)
find_package(Git REQUIRED)
execute_process(
	COMMAND ${GIT_EXECUTABLE} rev-parse HEAD
	RESULT_VARIABLE result
	OUTPUT_VARIABLE FooBar_GIT_HASH
	OUTPUT_STRIP_TRAILING_WHITESPACE
	)

if(result)
	message(FATAL_ERROR "Failed to get git hash: ${result}")
endif()


execute_process(
	COMMAND ${GIT_EXECUTABLE} rev-list -1 HEAD projectVersionDetails.cmake
	RESULT_VARIABLE result
	OUTPUT_VARIABLE lastChangeHash
	OUTPUT_STRIP_TRAILING_WHITESPACE
	)

if(result)
	message(FATAL_ERROR "Failed to get hash of last change: ${result}")
endif()

execute_process(
	COMMAND ${GIT_EXECUTABLE} rev-list ${lastChangeHash}..HEAD
	RESULT_VARIABLE result
	OUTPUT_VARIABLE hashList
	OUTPUT_STRIP_TRAILING_WHITESPACE
	)

if(result)
	message(FATAL_ERROR "Failed to get list of git hashes: ${result}")
endif()

string(REGEX REPLACE "[\n\r]+" ";" hashList "${hashList}")
list(LENGTH hashList FooBar_COMMITS_SINCE_VERSION_CHANGE)

configure_file(foobar_version.h.in
	foobar_version.h @ONLY)

add_executable(foobar master.cpp)

add_library(app SHARED app.cpp)

# target_include_directories(app
#         PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
#         )

target_link_libraries(foobar
	PRIVATE app
	)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
