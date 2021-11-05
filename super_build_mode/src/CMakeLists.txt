# ------------------------------- #
# source 'CMakeLists.txt' Example # 
# ------------------------------- #

# Step 1: Declare an c++ project, 
# and config default settings for the build-type of the project.
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(sup-simple-base LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Step 2: Project need message library
find_package(message 1 CONFIG REQUIRED)
get_property(_loc TARGET message::message-shared PROPERTY LOCATION)
message(STATUS "Found message: ${_loc} (found version ${message_VERSION})")

# Step 3: Declare an executable target, and make it linked with the message library
add_executable(use_message use_message.cpp)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/execute)

target_link_libraries(
	use_message
	PUBLIC
		message::message-shared
	)
