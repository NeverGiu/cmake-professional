add_executable(test test.cpp)

add_library(tartype 
	SHARED
	tar.cpp
)

target_link_libraries(
	test PRIVATE tartype
)
