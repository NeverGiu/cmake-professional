# Step 1: Find packages 'Perl, Doxygen'
find_package(Perl REQUIRED)
find_package(Doxygen REQUIRED)

# Step 2: Declare function 'add_doxygen_doc', and usage function
# 'cmake_parse_arguments' to parsing these arguments below
function(add_doxygen_doc)
	set(options)
	set(oneValueArgs BUILD_DIR DOXY_FILE TARGET_NAME COMMENT)
	set(multiValueArgs)

	cmake_parse_arguments(DOXY_DOC
		"${options}"
		"${oneValueArgs}"
		"${multiValueArgs}"
		${ARGN}
		)

	# Step 3: The template file 'Doxyfile.in' will passed DOXY_FILE argument,
	# and parsing to be variable name 'DOXY_DOC_DOXY_FILE'.
	configure_file(
		${DOXY_DOC_DOXY_FILE}
		${DOXY_DOC_BUILD_DIR}/Doxyfile
		@ONLY
		)
	
	# Step 4: Then define a named 'DOXY_DOC_TARGET_NAME' custom target, 
	# and output result in 'DOXY_DOC_BUILD_DIR'
	add_custom_target(${DOXY_DOC_TARGET_NAME}
		COMMAND
			${DOXYGEN_EXECUTABLE} Doxyfile
		WORKING_DIRECTORY
			${DOXY_DOC_BUILD_DIR}
		COMMENT
			"Building ${DOXY_DOX_COMMENT} with Doxygen"
		VERBATIM
		)

	# Step 5: Finally, send a message to user.
	message(STATUS "Added ${DOXY_DOX_TARGET_NAME} [Doxygen] target to build documentation")
endfunction()

