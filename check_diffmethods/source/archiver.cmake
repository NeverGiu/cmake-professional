cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

if(NOT TAR_DIR)
	message(FATAL_ERROR "TAR_DIR must be set")
endif()

set(archive archive.tar)
execute_process(COMMAND ${CMAKE_COMMAND} -E tar cf ${archive} "${TAR_DIR}"
	RESULT_VARIABLE result
)

if(result)
	message(FATAL_ERROR "Archiving ${TAR_DIR} failed: ${result}")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} -E md5sum ${archive}
	OUTPUT_VARIABLE md5output
	RESULT_VARIABLE result
)

if(result)
	message(FATAL_ERROR "Unable to compute md5 of archive: ${result}")
endif()

string(REGEX MATCH "^ *[^ ]*" md5sum "${md5output}")
message(STATUS "Archiving MD5 checksum: ${md5sum}")
