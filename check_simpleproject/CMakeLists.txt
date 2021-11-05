# 1 step: config cmake requireds
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# 2 step: config project attributes
project(simpleproject 
	VERSION 1.0.0
	LANGUAGES CXX
)

# 3 step: config executes
add_executable(hello main.cpp)

# 4 step: config libs
if(BUILD_SHARED_LIBS)
	add_library(core 
		SHARED
		apple.cpp
		orange.cpp
	)
	add_library(info
		SHARED
		printinfo.cpp
	)
else()
	add_library(core 
		STATIC
		apple.cpp
		orange.cpp
	)
	add_library(info
		STATIC
		printinfo.cpp
	)
endif()

# 5 step: config linking
target_link_libraries(info
	PRIVATE	core
)
target_link_libraries(hello
	PRIVATE	info
)
