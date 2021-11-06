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

# Step 2: Build a dynamic library, and specify the source file
add_library(message-shared SHARED "")
target_sources(message-shared
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/Message.cpp
	)

# Step 3: Declare linked library when compiling. Note: all these items 
# are PUBLIC to make sure all targets depends on them can inherit correctly.
target_compile_definitions(message-shared
	PUBLIC
		$<$BOOL:${UUID_FOUND}>:HAVE_UUID>
	)

target_link_libraries(message-shared
	PUBLIC
		$<$<BOOL:${UUID_FOUND}>:PkgConfig::UUID>
	)

# Step 4: Set additional attributes of the target.
set_target_properties(message-shared
	PROPERTIES
		POSITION_INDEPENDENT_CODE 1
		SOVERSION ${PROJECT_VERSION_MAJOR}
		OUTPUT_NAME "message"
		DEBUG_POSTFIX "_d"
		PUBLIC_HEADER "Message.h"
		MACOSX_RPATH ON
		WINDOWS_EXPORT_ALL_SYMBOLS ON
		)

# Step 5: Finally, add executable file for 'Hello, World', and linked it with library.
add_executable(hello-world_wDSO hello-world.cpp)
target_link_libraries(hello-workd_wDSO
	PUBLIC 
		message-shared
	)
