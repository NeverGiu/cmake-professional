cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(simple-test VERSION 1.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(source)
set(MSG_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/source)
set(MSG_LIBRARY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/source/msg.cpp)
set(MAIN_CPP_PATH ${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp)
set(FOO_CPP_PATH ${CMAKE_CURRENT_SOURCE_DIR}/source/fooTest.cpp)
set(BAR_CPP_PATH ${CMAKE_CURRENT_SOURCE_DIR}/source/barTest.cpp)
set(OTHER_CPP_PATH ${CMAKE_CURRENT_SOURCE_DIR}/source/other_foo.cpp)

set(MSG_LIB_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set(BIN_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

include_directories(${MSG_INCLUDE_PATH})
add_library(msg SHARED ${MSG_LIBRARY_PATH})
set(LIBRARY_OUTPUT_PATH ${MSG_LIB_OUTPUT_PATH})

add_executable(main ${MAIN_CPP_PATH})
target_link_libraries(
	main
	PRIVATE msg
	)

add_executable(cpp_fooTest ${FOO_CPP_PATH})
target_link_libraries(
	cpp_fooTest
	PRIVATE msg
	)

add_executable(cpp_barTest ${BAR_CPP_PATH})
target_link_libraries(
	cpp_barTest
	PRIVATE msg
	)

add_executable(cpp_other_foo ${OTHER_CPP_PATH})
target_link_libraries(
	cpp_other_foo
	PRIVATE msg
	)

set(EXECUTABLE_OUTPUT_PATH ${BIN_OUTPUT_PATH})

enable_testing()

add_test(
	NAME cpp_fooTest
	COMMAND $<TARGET_FILE:cpp_fooTest>
	)
set_tests_properties(
	cpp_fooTest PROPERTIES
	ENVIRONMENT "CTEST_OUTPUT_ON_FAILURE=1"
	SKIP_RETURN_CODE 2
	LABELS "foo"
	)

add_test(
	NAME cpp_barTest
	COMMAND $<TARGET_FILE:cpp_barTest>
	)
set_tests_properties(
	cpp_barTest PROPERTIES
	DISABLED YES
	LABELS "bar"
	)

add_test(
	NAME cpp_other_foo
	COMMAND $<TARGET_FILE:cpp_other_foo>
	)
set_tests_properties(
	cpp_other_foo PROPERTIES
	ENVIRONMENT "CTEST_OUTPUT_ON_FAILURE=1"
	SKIP_RETURN_CODE 2
	LABELS "foo"
	)
