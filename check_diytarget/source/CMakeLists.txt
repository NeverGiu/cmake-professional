add_executable(generator master.cpp)

add_library(hash SHARED api.cpp hasher.cpp)

target_link_libraries(generator
	PRIVATE hash)

# add_custom_command(OUTPUT onTheFly.cpp
#         COMMAND generator)
#
# add_executable(execute ${CMAKE_CURRENT_BINARY_DIR}/onTheFly.cpp)

# add_custom_command(OUTPUT generator.cpp
#         COMMAND writeHash $<TARGET_FILE:generator>)

# message(STATUS "CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")
# add_custom_target(computeHash
#         DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/hasher.cpp)
#
# execute_process(COMMAND computeHash
#         RESULT_VARIABLE result)
# if(result)
#         message(FATAL_ERROR "Run generator failed: ${result}")
# endif()
