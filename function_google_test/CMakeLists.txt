# Project basical config
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(google-test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(source)

# Create library
add_library(username SHARED ${PROJECT_SOURCE_DIR}/source/username.cpp)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# Create executable 'main' 
add_executable(main ${PROJECT_SOURCE_DIR}/source/main.cpp)
target_link_libraries(main PRIVATE username)

# Unit-test switch
option(ENABLE_UNIT_TESTS "Enable unit tests" ON)
message(STATUS "Enable testing: ${ENABLE_UNIT_TESTS}")

if(ENABLE_UNIT_TESTS)
	# Get module 'google-test'
	include(FetchContent)

	FetchContent_Declare(
		googletest
		GIT_REPOSITORY https://github.com.cnpmjs.org/google/googletest.git
		GIT_TAG release-1.8.0
		)

	FetchContent_GetProperties(googletest)

	# If we can't get googletest, we will download it in local place.
	# if(NOT googletest_POPULATED)
        #         FetchContent_Populate(googletest)
        #         # Prevent GoogleTest from overriding our compiler/linker options
        #         # when building with Visual Studio
        #         set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
        #         # Prevent GoogleTest from using PThreads
        #         set(gtest_disable_pthreads ON CACHE BOOL "" FORCE)
        #         # adds the targers: gtest, gtest_main, gmock, gmock_main
        #         add_subdirectory(
        #           ${googletest_SOURCE_DIR}
        #           ${googletest_BINARY_DIR}
        #           )
        #         # Silence std::tr1 warning on MSVC
        #         if(MSVC)
        #           foreach(_tgt gtest gtest_main gmock gmock_main)
        #             target_compile_definitions(${_tgt}
        #               PRIVATE
        #                   "_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING"
        #             )
        #           endforeach()
        #         endif()
        # endif()

	# Create cpp_test
	add_executable(cpp_test ${PROJECT_SOURCE_DIR}/source/test.cpp)
	set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
	
	target_link_libraries(
		cpp_test
		PRIVATE username
		)
	
	enable_testing()
	
	add_test(
		NAME google_test
		COMMAND $<TARGET_FILE:cpp_test>
		)
	set_tests_properties(
		google_test PROPERTIES
		ENVIRONMENT "CTEST_OUTPUT_ON_FAILURE=1"
		SKIP_RETURN_CODE 2
		)
endif()
