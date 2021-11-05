# function(print_me)
#         message(STATUS "Hello from inside a function.")
#         message(STATUS "All done.")
#
# endfunction(print_me)
#
# if("Hi from ${who}" MATCHES "Hi from (NeverGiu|Barney).*")
#         message(STATUS "${CMAKE_MATCH_1} says hello")
# else()
#         message(STATUS "Building shut down.")
#         return()
# endif()
#
# message(STATUS "===========================")
# print_me()

# function(func arg)
#         if(DEFINED arg)
#                 message(STATUS "Function arg is a defined variable.")
#         else()
#                 message(STATUS "Function arg is an undefined variable.")
#         endif()
# endfunction(func arg)
#
# macro(macr arg)
#         if(DEFINED arg)
#                 message(STATUS "Macro arg is a defined variable.")
#         else()
#                 message(STATUS "Macro arg is an undefined variable.")
#         endif()
# endmacro(macr arg)
#
# func(foobar)
# macr(foobar)

# function(func myArg)
#         message(STATUS "myArg = ${myArg}")
# endfunction(func myArg)
#
# macro(macr myArg)
#         message(STATUS "myArg = ${myArg}")
# endmacro(macr myArg)
#
# func(foobar)
# macr(foobar)

# function(add_mytest targetName)
#         add_executable(${targetName} ${ARGN})
#         # target_link_libraries(${targetName} PRIVATE foobar)
#         add_test(NAME ${targetName}
#                 COMMAND ${targetName}
#         )
# endfunction(add_mytest targetName)
#
# add_mytest(smallTest small.cpp)
# add_mytest(bigTest big.cpp)
# add_mytest(bigTest big.cpp algo.cpp net.cpp)

# macro(dangerous)
#         foreach(arg IN ITEMS ${ARGN})
#                 message(STATUS "Argument: ${arg}")
#         endforeach()
# endmacro()
#
# function(func)
#         dangerous(1 2 3)
# endfunction(func)
#
# func(4)

# function(func)
#         # Define the supported set of keywords
#         set(prefix ARG)
#         set(noValues ENABLE_NET COOL_STUFF)
#         set(singleValues TARGET)
#         set(multiValues SOURCES IMAGES)
#
#         # Process the arguments passed in
#         include(CMakeParseArguments)
#         cmake_parse_arguments(${prefix}
#                                 "${noValues}"
#                                 "${singleValues}"
#                                 "${multiValues}"
#                                 ${ARGN})
#
#         # Log details for each supported keyword
#         message(STATUS "Option summary: ")
#         foreach(arg IN LISTS noValues)
#                 if(${${prefix}_${arg}})
#                         message(STATUS "${arg} enabled.")
#                 else()
#                         message(STATUS "${arg} disabled.")
#                 endif()
#         endforeach(arg IN LISTS noValues)
#
#         foreach(arg IN LISTS singleValues multiValues)
#                 # Single argument vvalues will print as a simple string
#                 # Multiple argument values will print as a list
#                 message(STATUS "${arg} = ${${prefix}_${arg}}")
#         endforeach(arg IN LISTS singleValues multiValues)
#
# endfunction(func)
#
# # Examples of calling with different combinations of keyword arguments
# func(SOURCES foo.cpp bar.cpp TARGET myApp ENABLE_NET)
# func(IMAGES here.png there.png gone.png TARGET dummy COOL_STUFF)

# function(func resultVar1 resultVar2)
#         set(${resultVar1} "First result" PARENT_SCOPE)
#         set(${resultVar2} "Second result" PARENT_SCOPE)
# endfunction(func resultVar1 resultVar2)
#
# func(myVar otherVar)
# message(STATUS "myVar = ${myVar}")
# message(STATUS "otherVar = ${otherVar}")

# macro(inner)
#         message(STATUS "From inner.")
#         return()
#         message(STATUS "Never printed.")
# endmacro()
#
# function(outer)
#         message(STATUS "From outer before calling inner.")
#         inner()
#         message(STATUS "Also never printed.")
# endfunction(outer)
#
# outer()

function(printme)
	message(STATUS "Hello from first.")	
endfunction(printme)

function(printme)
	message(STATUS "Hello from second.")	
	_printme()
endfunction(printme)

function(printme)
	message(STATUS "Hello from third.")	
	_printme()
endfunction(printme)

printme()
