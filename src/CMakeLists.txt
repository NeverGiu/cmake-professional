# --------------------- #
#     Src CMake File    #
# --------------------- #

# Dynamic library
# ---------------
# Step 1: Build a dynamic library, and specify the source file
add_library(message-shared SHARED 
	Message.h
	Message.cpp
	)

# Step 2: Add executable file for 'Hello, World', and linked it with library.
add_executable(hello-world hello-world.cpp)
target_link_libraries(hello-world
	PUBLIC 
		message-shared
	)
