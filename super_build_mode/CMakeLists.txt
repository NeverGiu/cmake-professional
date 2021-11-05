# ----------------------------- #
# Main 'CMakeLists.txt' Example # 
# ----------------------------- #

# Step 1: Declare an c++ project, 
# and config default settings for the build-type of the project.
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(sup-simple-base LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT DEFINED CMAKE_BUILD_TYPE OR "${CMAKE_BUILD_TYPE}" STREQUAL "")
	set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

message(STATUS "Build type set to ${CMAKE_BUILD_TYPE}")

# Step 2: Set 'EP_BASE' directory property,
# it will manage all sub-projects's layout.
set_property(DIRECTORY PROPERTY EP_BASE ${CMAKE_BINARY_DIR}/subprojects)

# Step 3: This location will be used as the installation directory 
# in the build tree of the dependencies.
set(STAGED_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/stage)
message(STATUS "${PROJECT_NAME} staged install: ${STAGED_INSTALL_PREFIX}")

# Step 4: Add subdirectory
add_subdirectory(external/upstream)

# Step 5: Add external project, out projcet will be managed by super-build-mode
include(ExternalProject)
ExternalProject_Add(${PROJECT_NAME}_core
	DEPENDS
		message_external
	SOURCE_DIR
		${CMAKE_CURRENT_SOURCE_DIR}/src
	CMAKE_ARGS
		-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
		-DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
		-DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}
		-DCMAKE_CXX_EXTENSIONS=${CMAKE_CXX_EXTENSIONS}
		-DCMAKE_CXX_STANDARD_REQUIRED=${CMAKE_CXX_STANDARD_REQUIRED}
		-Dmessage_DIR=${message_DIR}
	CMAKE_CACHE_ARGS
		-DCMAKE_CXX_FLAGS:STRING=${CMAKE_CXX_FLAGS}
		-DCMAKE_PREFIX_PATH:PATH=${CMAKE_PREFIX_PATH}
	BUILD_ALWAYS
		1
	INSTALL_COMMAND
		""
	)
