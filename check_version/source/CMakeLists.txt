configure_file(foobar_version.h.in
	foobar_version.h @ONLY)

add_executable(foobar master.cpp)

add_library(app SHARED app.cpp)

target_include_directories(app
	PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
	)

# message(STATUS "AT SOURCE DIR: PROJECT_BINARY_DIR = ${PROJECT_BINARY_DIR}")
# message(STATUS "AT SOURCE DIR: PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")
# message(STATUS "AT SOURCE DIR: CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR}")
# message(STATUS "AT SOURCE DIR: CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(foobar
	PRIVATE app
	)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
