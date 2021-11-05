# set(customPath ${CMAKE_CURRENT_BINARY_DIR}/outPath)
# file(TO_CMAKE_PATH ${customPath} outVar)

set(FOO "Strint with spaces")
configure_file(various.txt.in ${PROJECT_BINARY_DIR}/bin/various.txt)

set(BAR "Some \"quoted\" value")
configure_file(quoting.txt.in ${PROJECT_BINARY_DIR}/bin/quoting.txt)
configure_file(quoting.txt.in ${PROJECT_BINARY_DIR}/bin/quoting_escaped.txt ESCAPE_QUOTES)

set(USER_FILE whoami.txt)
configure_file(whoami.sh.in ${PROJECT_BINARY_DIR}/bin/whoami.sh @ONLY)

file(COPY whoami.sh.in
	DESTINATION ${PROJECT_BINARY_DIR}/temp
	FILE_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
	GROUP_READ GROUP_EXECUTE
	WORLD_READ WORLD_WRITE
	)

set(msg "Hello world ")
file(WRITE ${PROJECT_BINARY_DIR}/bin/hello.txt ${msg})
file(APPEND ${PROJECT_BINARY_DIR}/bin/hello.txt "from CMake.")

file(WRITE ${PROJECT_BINARY_DIR}/bin/multi.txt [[
	First line
	Second line
	]])

file(WRITE ${PROJECT_BINARY_DIR}/bin/userCheck.sh [=[
	#!/bin/bash
	[[ -n "${USER}" ]] && echo "Have USER"
	]=])

file(GENERATE
	OUTPUT ${PROJECT_BINARY_DIR}/bin/outFile-$<CONFIG>.txt
	INPUT ${CMAKE_CURRENT_SOURCE_DIR}/input.txt.in
	CONDITION $<NOT:$<CONFIG:Release>>
	)

file(GENERATE
	OUTPUT ${PROJECT_BINARY_DIR}/bin/details-$<CONFIG>.txt
	CONTENT [[
	Build as "$<CONFIG>" for platform "$<PLATFORM_ID>".
	]])

# file(STRINGS ${CMAKE_CURRENT_SOURCE_DIR}/myStory.txt versionLines
#         REGEX "(PKG|MODULE)_VERSION"
#         )
#
# set(regex "^ *FOO_VERSION *= *([^ ]+) *$")
# file(STRINGS ${CMAKE_CURRENT_SOURCE_DIR}/config.txt fooVersion
#         REGEX "${regex}"
#         )
# string(REGEX REPLACE "${regex}" "\\1" fooVersion "${fooVersion}")
file(DOWNLOAD "https://www.bookstack.cn/read/CMake-Cookbook/content-chapter9-9.2-chinese.md"
	${PROJECT_BINARY_DIR}/bin/cmake-cookbook.html SHOW_PROGRESS
	# EXPECTED_HASH SHA1=${myfileHash}
	
	)

file(GENERATE
	OUTPUT ${PROJECT_BINARY_DIR}/bin/cmake-cookbook-html-$<CONFIG>.txt
	CONTENT [[
	HTTPHEADER "Host: www.bookstack.cn/read/CMake-Cookbook"
	HTTPHEADER "Date: ${timestamp}"
	HTTPHEADER "Content-Type: application/x-compressed-tar"
	HTTPHEADER "Authorization: AWS ${s3key}:${signature}"
	]])
