# add_library(objLib OBJECT src1.cpp src2.cpp)
#
# add_executable(app1 app1.cpp $<TARGET_OBJECTS:objLib>)
# add_executable(app2 app2.cpp $<TARGET_OBJECTS:objLib>)

add_executable(myApp main.cpp)
add_executable(myAlias ALIAS myApp)
add_library(myLib SHARED lib.cpp)

include(CMakePrintHelpers)
cmake_print_properties(
	TARGETS myApp myLib myAlias
	PROPERTIES TYPE ALIASED_TARGET
	)

set(foo "My variable")
unset(bar)

cmake_print_variables(foo bar CMAKE_VERSION PROJECT_VERSION)

target_link_libraries(myApp
	PRIVATE myLib
	)
