# --------------------- #
#    Main CMake File    #
# --------------------- #

# Step 1: Declare cmake version and config project's settings.
cmake_minimum_required(VERSION 3.6 FATAL_ERROR)
project(sup-install-build 
	LANGUAGES CXX
	VERSION 1.0.0
	)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Step 2: Send project install message to user.
message(STATUS "Project will be installed to ${CMAKE_INSTALL_PREFIX}")

# Step 3: Config project with Release-Mod(default case).
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()
message(STATUS "Build type set to ${CMAKE_BUILD_TYPE}")

# Step 4: Tell CMake where can we build executable, static, shared library targets.
# So we can visiting them in non-install project case. Here we usage GNUInstallDirs.cmake 
# module to make sure that our project-tree is suitable and can-moveable.
include(GNUInstallDirs)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
	${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
	${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
	${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# Step 5: However, we've configured targets output location which are in build-dir,
# but needs commands to config the files's position that contains in executable, 
# library and install-prefix(we defineds new INSTALL_LIBDIR, INSTALL_BINDIR,
# INSTALL_INCLUDEDIR and INSTALL_CMAKEDIR).
set(INSTALL_LIBDIR ${CMAKE_INSTALL_LIBDIR} 
	CACHE PATH "Installation directory for libraries")
set(INSTALL_BINDIR ${CMAKE_INSTALL_BINDIR}
	CACHE PATH "Installation directory for executables")
set(INSTALL_INCLUDEDIR ${CMAKE_INSTALL_INCLUDEDIR} 
	CACHE PATH "Installation directory for header files")

if(WIN32 AND NOT CYGWIN)
	set(DEF_INSTALL_CMAKEDIR CMake)
else()
	set(DEF_INSTALL_CMAKEDIR share/cmake/${PROJECT_NAME})
endif()

set(INSTALL_CMAKEDIR ${DEF_INSTALL_CMAKEDIR} 
	CACHE PATH "Installation directory for CMake files")

# Step 6: Report the installation path to user.
foreach(p LIB BIN INCLUDE CMAKE)
	file(TO_NATIVE_PATH ${CMAKE_INSTALL_PREFIX}/${INSTALL_${P}DIR} _path)
	message(STATUS "Installing ${p} components to ${_path}")
	unset(_path)
endforeach()

# Step 7: Add sub-directorys(src, tests)
add_subdirectory(src)

enable_testing()

add_subdirectory(tests)

include(CMakeCPack.cmake)
