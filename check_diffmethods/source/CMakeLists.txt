add_executable(generateFiles generateFiles.cpp)

set(outDir "foo")
add_custom_target(archiver
	COMMAND ${CMAKE_COMMAND} -E echo "Archiving generated files"
	COMMAND ${CMAKE_COMMAND} -E remove_directory "${outDir}"
	COMMAND ${CMAKE_COMMAND} -E make_directory "${outDir}"
	COMMAND generateFiles "${outDir}"
	COMMAND ${CMAKE_COMMAND} "-DTAR_DIR=${outDir}"
	-p "${CMAKE_CURRENT_SOURCE_DIR}/archiver.cmake"
)
