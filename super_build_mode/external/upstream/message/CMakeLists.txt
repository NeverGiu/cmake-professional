# Step 1: Find a suitable version library.
find_package(message 1 CONFIG QUIET)

if(message_FOUND)
	# Step 2: If find item, we will send a message to user,
	# and add a virtual interface library.
	get_property(_loc TARGET message::message-shared PROPERTY LOCATION)
	message(STATUS "Found message: ${_loc} (found version ${message_VERSION})")
	add_library(message_external INTERFACE)# dummy
else()
	# Step 3: If we can't find, then send a message to user,
	# that we will using 'external project' continually. 
	message(STATUS "Suitable message could not be located, Building message instead.")

	# Step 4: The project is hosted in a public Git repository.
	# Usage the GIT_TAG option to specify wich branch to download.
	include(ExternalProject)
	ExternalProject_Add(message_external
		GIT_REPOSITORY
			https://github.com.cnpmjs.org/dev-cafe/message.git
		GIT_TAG
			master
		UPDATE_COMMAND
			""
		# Step 5: The external project is configured and built using CMake,
		# passing the necessary build options
		CMAKE_ARGS
			-DCMAKE_INSTALL_PREFIX=${STAGED_INSTALL_PREFIX}
			-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
			-DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
			-DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}
			-DCMAKE_CXX_EXTENSIONS=${CMAKE_CXX_EXTENSIONS}
			-DCMAKE_CXX_STANDARD_REQUIRED=${CMAKE_CXX_STANDARD_REQUIRED}
		CMAKE_CACHE_ARGS
			-DCMAKE_CXX_FLAGS:STRING=${CMAKE_CXX_FLAGS}
		# Step 6: We will testing program after installation
		TEST_AFTER_INSTALL
			1
		# Step 7: We will testing program quietly
		DOWNLOAD_NO_PROGRESS
			1
		LOG_CONFIGURE
			1
		LOG_BUILD
			1
		LOG_INSTALL
			1
		)

	# Step 8: Make sure our subdirs's other parts can be seen in super-build-mode.
	if(WIN32 AND NOT CYGWIN)
		set(DEF_message_DIR ${STAGED_INSTALL_PREFIX}/CMake)
	else()
		set(DEF_message_DIR ${STAGED_INSTALL_PREFIX}/share/cmake/message)
	endif()

	file(TO_NATIVE_PATH "${DEF_message_DIR}" DEF_message_DIR)
	set(message_DIR ${DEF_message_DIR}
		CACHE PATH "Path to internally built messageConfig.cmake" FORCE)
endif()
