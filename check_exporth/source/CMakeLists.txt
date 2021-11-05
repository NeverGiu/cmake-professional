# NOTE: myTools.cpp must #include myTools.h
add_library(myTools SHARED myTools.cpp)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
target_include_directories(myTools 
	PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

# Usage deprecated option
option(OMIT_DEPRECATED "Leave out deprecated parts of 'myTools'")
if(OMIT_DEPRECATED)
	set(deprecatedOption "DEFINE_NO_DEPRECATED")
else()
	unset(deprecatedOption)
endif()

# Write out mytools_exprot.h(export_myTools.h) to the current binary directory
include(GenerateExportHeader)
generate_export_header(myTools
	EXPORT_FILE_NAME export_myTools.h
	EXPORT_MACRO_NAME API_MYTOOLS
	NO_EXPORT_MACRO_NAME REALLY_PRIVATE
	NO_DEPRECATED_MACRO_NAME OMIT_DEPRECATED	
	${deprecatedOption}
	)

add_executable(master master.cpp)
target_link_libraries(master PRIVATE myTools)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
