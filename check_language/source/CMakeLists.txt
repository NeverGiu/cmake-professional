add_executable(baseInfo Info.cpp)
add_library(foo Base.cpp)

target_include_directories(foo
	PUBLIC "${CMAKE_CURRENT_BINARY_DIR}"
)

message(STATUS "CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR}")

target_link_libraries(baseInfo
	PRIVATE foo 
)

