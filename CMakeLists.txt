# --------------------- #
#    Main CMake File    #
# --------------------- #

# Step 1: Declare cmake version and config project's settings.
cmake_minimum_required(VERSION 3.6 FATAL_ERROR)
project(sup-build-doc
	LANGUAGES CXX
	VERSION 1.0.0
	)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Step 2: Tell CMake where can we build executable, static, shared library targets.
# So we can visiting them in non-install project case. Here we usage GNUInstallDirs.cmake 
# module to make sure that our project-tree is suitable and can-moveable.
include(GNUInstallDirs)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
	${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
	${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
	${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# Step 3: Add subdirector cmake path.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Step 4: Add UseDoxygenDoc.cmake
include(UseDoxygenDoc)

# Step 5: Add sub-directorys(src)
add_subdirectory(src)

add_doxygen_doc(
	BUILD_DIR
		${CMAKE_CURRENT_BINARY_DIR}/_build
	DOXY_FILE
		${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in
	TARGET_NAME
		docs
	COMMENT
		"HTML documentation"
	)
