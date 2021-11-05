add_library(cop STATIC component.cpp)

add_library(msg SHARED message.cpp)
target_link_libraries(msg PUBLIC cop)
set_target_properties(msg PROPERTIES
	VERSION 1.0.1
	SOVERSION 2
	)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_executable(master master.cpp)
target_link_libraries(master PRIVATE msg)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
