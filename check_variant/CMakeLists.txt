cmake_minimum_required(VERSION 3.9 FATAL_ERROR)

project(variant VERSION 1.0.0 LANGUAGES CXX)

# set(longStr abcdefabcdef)
# set(shortBit def)
#
# string(FIND ${longStr} ${shortBit} fwdIndex)
# string(FIND ${longStr} ${shortBit} revIndex REVERSE)
# message(STATUS "fwdIndex = ${fwdIndex}, revIndex = ${revIndex}")
#
# string(REGEX MATCHALL "[ace]" matchVar ${longStr})
# string(REGEX REPLACE "([de])" "X\\1Y" replVar ${longStr})
#
# string(LENGTH ${longStr} len)
# string(TOLOWER ${longStr} tolow)
# string(TOUPPER ${longStr} toup)
# string(STRIP ${longStr} ip)
#
# message(STATUS "matchVar = ${matchVar}")
# message(STATUS "replVar = ${replVar}")
#
# message(STATUS "len = ${len}")
# message(STATUS "tolow = ${tolow}")
# message(STATUS "toup = ${toup}")
# message(STATUS "ip = ${ip}")
#
# set(myList a b c)
#
# list(APPEND myList f d e)
# message(STATUS "myList (first) = ${myList}")
# list(INSERT myList 3 Z Y X)
# message(STATUS "myList (second) = ${myList}")
#
# list(LENGTH myList listlen)
# message(STATUS "listlen = ${listlen}")
# list(GET myList 2 1 letters)
# message(STATUS "letters = ${letters}")
#
# list(FIND myList X Xindex)
# message(STATUS "Xindex = ${Xindex}")
#
# list(SORT myList)
# message(STATUS "myList (third) = ${myList}")
#
# set(i 3)
# set(j 7)
# math(EXPR average "(${i}+${j}) / 2")
# message(STATUS "average = ${average}")

# Valid numeric expressions, all evaluating as true
# set(a 2)
# set(b 1)
# set(c "23")
# set(d 23)

# Invalid expression that evaluates as true with at least
# some CMake versions. Do not rely on this behaviour.
# set(e "23a")
# set(val 42)
#
# if(${a} GREATER ${b})
#         message(STATUS "${a} > ${b}")
# else()
#         message(STATUS "${a} <= ${b}")
# endif()
#
# if(${c} EQUAL ${d})
#         message(STATUS "${c} == ${d}")
# else()
#         message(STATUS "${c} != ${d}")
# endif()
#
# if(${val} EQUAL 42)
#         message(STATUS "${val} == 42")
# else()
#         message(STATUS "${val} != 42")
# endif()
#
# if("${val}" EQUAL 42)
#         message(STATUS "\"${val}\" == 42")
# else()
#         message(STATUS "\"${val}\" != 42")
# endif()
#
# if(${e} EQUAL ${d})
#         message(STATUS "${e} == ${d}")
# else()
#         message(STATUS "${e} != ${d}")
# endif()

# if(1.2 VERSION_EQUAL 1.2.0)
#         message(STATUS "version 1.2 == version 1.2.0")
# else()
#         message(STATUS "version 1.2 != version 1.2.0")
# endif()
#
# if(1.2 VERSION_LESS 1.2.3)
#         message(STATUS "version 1.2 < version 1.2.3")
# else()
#         message(STATUS "version 1.2 >= version 1.2.3")
# endif()
#
# if(1.2.3 VERSION_GREATER 1.2)
#         message(STATUS "version 1.2.3 > version 1.2")
# else()
#         message(STATUS "version 1.2.3 <= version 1.2")
# endif()
#
# if(2.0.1 VERSION_GREATER 1.9.7)
#         message(STATUS "version 2.0.1 > version 1.9.7")
# else()
#         message(STATUS "version 2.0.1 <= version 1.9.7")
# endif()
#
# if(1.8.2 VERSION_LESS 2)
#         message(STATUS "version 1.8.2 < version 2")
# else()
#         message(STATUS "version 1.8.2 >= version 2")
# endif()
 
if("Hi from ${who}" MATCHES "Hi from (NeverGiu|Barney).*")
	message(STATUS "${CMAKE_MATCH_1} says hello")
endif()

# set(logPath ${CMAKE_CURRENT_SOURCE_DIR}/log)
# if(EXISTS ${logPath})
#         message(STATUS "File '${logPath}' exist.")
# else()
#         message(STATUS "File '${logPath}' does not exist.")
# endif()
#
# set(cmakeFloderPath ${CMAKE_CURRENT_SOURCE_DIR}/CMakeFiles)
# if(IS_DIRECTORY ${cmakeFloderPath})
#         message(STATUS "Dir '${cmakeFloderPath}' exist.")
# else()
#         message(STATUS "Dir '${cmakeFloderPath}' does not exist.")
# endif()
#
# set(cmakeListsPath ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt)
# if(IS_SYMLINK ${cmakeListsPath})
#         message(STATUS "Symbol link '${cmakeListsPath}' exist.")
# else()
#         message(STATUS "Symbol link '${cmakeListsPath}' does not exist.")
# endif()
#
# set(srcPath1 ${CMAKE_CURRENT_SOURCE_DIR})
# set(srcPath2 ${../cmake_professional/check_variant})
# if(IS_ABSOLUTE ${srcPath1})
#         message(STATUS "Source path '${srcPath1}' is absolute.")
# elseif(NOT IS_ABSOLUTE ${srcPath2})
#         message(STATUS "Source path '${srcPath2}' is relative.")
# else()
#         message(STATUS "Source path '${srcPath1}' is relative.")
#         message(STATUS "Source path '${srcPath2}' is absolute.")
# endif()
#
# if(${logPath} IS_NEWER_THAN ${cmakeListsPath})
#         message(STATUS "File 'log' is similar with file 'CMakeLists.txt'.")
# else()
#         message(STATUS "File 'log' is different with file 'CMakeLists.txt'.")
# endif()

# if(CMAKE_GENERATOR STREQUAL "Ninja")
#         message(STATUS "Config compiler --Ninja.")
# elseif(CMAKE_GENERATOR STREQUAL "Xcode")
#         message(STATUS "Config compiler --Xcode.")
# elseif(CMAKE_GENERATOR STREQUAL "Clang")
#         message(STATUS "Config compiler --Clang.")
# else()
#         message(STATUS "Config compiler --Generic.")
# endif()

# add_executable(platinfo ${platformImpl})

# set(list1 A B C D E F G H I G K L M N)
# set(list2 O P Q)
# set(foo WillNotBeShown)
#
# foreach(loopVar IN LISTS list1 list2 ITEMS bar foo)
#         message(STATUS "Iteration for: ${loopVar}")
# endforeach()

foreach(outerVar IN ITEMS a b c)
	unset(s)
	foreach(innerVar IN ITEMS 1 2 3)
		list(APPEND s "${outerVar}${innerVar}")
		string(LENGTH s length)
		if(length GREATER 5)
			break()
		endif()

		if(outerVar STREQUAL "b")
			continue()
		endif()
		message(STATUS "Processing ${outerVar}-${innerVar}")
		
	endforeach(innerVar IN ITEMS 1 2 3)
	
	message(STATUS "Accumulated list: ${s}")	
endforeach(outerVar IN ITEMS a b c)
