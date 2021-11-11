add_library(sum_integers SHARED "")
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

target_sources(sum_integers
	PRIVATE
		sum_integers.cpp
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}/sum_integers.h
	)

target_include_directories(sum_integers
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}
	)

add_executable(sum_up main.cpp)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

target_link_libraries(sum_up sum_integers)
