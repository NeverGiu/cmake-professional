add_library(myShared SHARED myShared.cpp)
add_library(myStatic STATIC myStatic.cpp)

include(GenerateExportHeader)
generate_export_header(myShared
	EXPORT_FILE_NAME mine_export.h
	EXPORT_MACRO_NAME MINE_EXPORT
	)

target_link_libraries(myShared
	PRIVATE myStatic
	)

set_target_properties(myStatic
	PROPERTIES POSITION_INDEPENDENT_CODE ON
	)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
add_library(myOtherStatic STATIC other.cpp)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
target_link_libraries(myShared
	PRIVATE myOtherStatic
	)

target_include_directories(myShared
	PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
	)
target_include_directories(myStatic
	PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
	)

target_compile_definitions(myStatic
	PRIVATE myShared_EXPORTS
	)

add_executable(master master.cpp)
target_link_libraries(master
	PUBLIC myShared
	)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
