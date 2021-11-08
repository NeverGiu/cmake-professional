# --------------------- #
#     Src CMake File    #
# --------------------- #

# Step 1: The project is depends on UUID.
find_package(PkgConfig QUIET)
if(PKG_CONFIG_FOUND)
	pkg_search_module(UUID uuid IMPORTED_TARGET)
	if(TARGET PkgConfig::UUID)
		message(STATUS "Found library uuid")
		set(UUID_FOUND TRUE)
	endif()
endif()

# Dynamic library
# ---------------
# Step 2: Build a dynamic library, and specify the source file
add_library(message-shared SHARED "")

# Step 5: Include 'GenerateExportHeader.cmake' module and calling 'generate_export_header'
# funcion, this action will generating 'messageExport.h' header.
include(GenerateExportHeader)
generate_export_header(message-shared
	BASE_NAME "message"
	EXPORT_MACRO_NAME "message_EXPORT"
	EXPORT_FILE_NAME "${CMAKE_BINARY_DIR}/${INSTALL_INCLUDEDIR}/messageExport.h"
	DEPRECATED_MACRO_NAME "message_DEPRECATED"
	NO_EXPORT_MACRO_NAME "message_NO_EXPORT"
	STATIC_DEFINE "message_STATIC_DEFINE"
	NO_DEPRECATED_MACRO_NAME "message_NO_DEPRECATED"
	DEFINE_NO_DEPRECATED
	)


target_sources(message-shared
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/Message.cpp
	)

# Step 3: Declare linked library when compiling. Note: all these items 
# are PUBLIC to make sure all targets depends on them can inherit correctly.
target_compile_definitions(message-shared
	PUBLIC
		$<$<BOOL:${UUID_FOUND}>:HAVE_UUID>
	INTERFACE
		$<INSTALL_INTERFACE:USING_message>
	)

# Step 6: When we will change visibility of symbols, we should include the header 
# that has been exported.
target_include_directories(message-shared
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/${INSTALL_INCLUDEDIR}>
		$<INSTALL_INTERFACE:${INSTALL_INCLUDEDIR}>
	)

target_link_libraries(message-shared
	PUBLIC
		$<$<BOOL:${UUID_FOUND}>:PkgConfig::UUID>
	)

# Step 4: Set additional attributes of the target.
set_target_properties(message-shared
	PROPERTIES
		POSITION_INDEPENDENT_CODE 1
		CXX_VISIBILITY_PRESET hidden
		VISIBILITY_INLINES_HIDDEN 1
		SOVERSION ${PROJECT_VERSION_MAJOR}
		OUTPUT_NAME "message"
		DEBUG_POSTFIX "_d"
		PUBLIC_HEADER "Message.h;${CMAKE_BINARY_DIR}/${INSTALL_INCLUDEDIR}/messageExport.h"
		MACOSX_RPATH ON
		WINDOWS_EXPORT_ALL_SYMBOLS ON
		)

# Static library
# --------------
# Step 7: Add an static library
add_library(message-static STATIC "")
target_sources(message-static
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/Message.cpp
	)

# Step 8: Because we add 'message_STATIC_DEFINE' compiling macro defination, 
# so make sure our symbols can been exposed suitable.
target_compile_definitions(message-static
	PUBLIC
		message_STATIC_DEFINE
		$<$<BOOL:${UUID_FOUND}>:HAVE_UUID>
	INTERFACE
		$<INSTALL_INTERFACE:USING_message>
	)

target_include_directories(message-static
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/${INSTALL_INCLUDEDIR}>
		$<INSTALL_INTERFACE:${INSTALL_INCLUDEDIR}>
	)

target_link_libraries(message-static
	PUBLIC 
		$<$<BOOL:${UUID_FOUND}>:PkgConfig::UUID>
	)

# Step 9: Config 'message-static' target's attributes.
set_target_properties(message-static
	PROPERTIES
		POSITION_INDEPENDENT_CODE 1
		ARCHIVE_OUTPUT_NAME "message"
		DEBUG_POSTFIX "_sd"
		RELEASE_POSTFIX "_s"
		PUBLIC_HEADER "Message.h;${CMAKE_BINARY_DIR}/${INSTALL_INCLUDEDIR}/messageExport.h"
	)

# Step 10: Finally, add executable file for 'Hello, World', and linked it with library.
add_executable(hello-world_wDSO hello-world.cpp)
target_link_libraries(hello-world_wDSO
	PUBLIC 
		message-shared
	)

# Step 11: Config message_RPATH, this will config suitable RPATH for GNU/Linux and macOS.
file(RELATIVE_PATH _rel ${CMAKE_INSTALL_PREFIX}/${INSTALL_BINDIR} ${CMAKE_INSTALL_PREFIX})
if(APPLE)
	set(_rpath "@loader_path/${_rel}")
else()
	set(_rpath "\$ORIGIN/${_rel}")
endif()
file(TO_NATIVE_PATH "${_rpath}/${INSTALL_LIBDIR}" message_RPATH)

# Step 12: Now we can using it to configuring executable target hello-world_wDSO's RPATH,
# and we can also set additional attributes.
set_target_properties(hello-world_wDSO
	PROPERTIES
		MACOSX_RPATH ON
		SKIP_BUILD_RPATH OFF
		BUILD_WITH_INSTALL_RPATH OFF
		INSTALL_RPATH "${message_RPATH}"
		INSTALL_RPATH_USE_LINK_PATH ON
		)

# Step 13: Also, we define another executable target 'hello-world_wAR', 
# it point to the static library.
add_executable(hello-world_wAR hello-world.cpp)
target_link_libraries(hello-world_wAR 
	PUBLIC
		message-static
	)

# Step 14: Finally, we can install libraries, headers and executable files.
install(
	TARGETS
		message-shared
		message-static
		hello-world_wDSO
		hello-world_wAR
	EXPORT
		messageTargets
	ARCHIVE
		DESTINATION ${INSTALL_LIBDIR}
		COMPONENT lib
	RUNTIME
		DESTINATION ${INSTALL_BINDIR}
		COMPONENT bin
	LIBRARY
		DESTINATION ${INSTALL_LIBDIR}
		COMPONENT lib
	PUBLIC_HEADER
		DESTINATION ${INSTALL_INCLUDEDIR}/message
		COMPONENT dev
	)

# Step 8: Auto creational exported target file 'messageTargets.cmake',
# needs to explicitly specify its installation rules. It's target is 
# 'INSTALL_CMAKEDIR'.
install(
	EXPORT
		messageTargets
	NAMESPACE
		"message::"
	DESTINATION
		${INSTALL_CMAKEDIR}
	COMPONENT
		dev
	)

# Step 9: Needs creating currectly CMake config file. This will make sure
# that downstream project can find the message library exported targets.
include(CMakePackageConfigHelpers)

# Create an version-message contained file for our library by CMake.
write_basic_package_version_file(
	${CMAKE_CURRENT_BINARY_DIR}/messageConfigVersion.cmake
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY SameMajorVersion
	)

# Step 10: Usage 'configure_package_config_file' function to create CMake config file.
configure_package_config_file(
	${PROJECT_SOURCE_DIR}/cmake/messageConfig.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/messageConfig.cmake
	INSTALL_DESTINATION ${INSTALL_CMAKEDIR}
	)

# Step 11: Finally, sets install rules for the two auto-created configure files.
install(
	FILES
		${CMAKE_CURRENT_BINARY_DIR}/messageConfig.cmake
		${CMAKE_CURRENT_BINARY_DIR}/messageConfigVersion.cmake
	DESTINATION
		${INSTALL_CMAKEDIR}
	)
