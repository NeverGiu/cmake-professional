# Step 1: Declare package name
set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")

# Step 2: Declare package vendor
set(CPACK_PACKAGE_VENDOR "NeverGiu")

# Step 3: The packaged sources contains an description file
set(CPACK_PACKAGE_DESCRIPTION_FILE "${PROJECT_SOURCE_DIR}/INSTALL.md")

# Step 4: Add an description summary of the package
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "message: This is a small messaging library.")

# Step 5: An license file is also included in the package
set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/LICENSE")

# Step 6: Sets local install directory
set(CPACK_PACKAGING_INSTALL_PREFIX "/home/nevergiu/TestApp/${PROJECT_NAME}")
message(STATUS "(Install Message): Your project will install at '/home/nevergiu/TestApp/${PROJECT_NAME}' when you run the binary-install-file")

# Step 7: Sets package version that CPack needed(major.minor.patch)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

# Step 8: Sets files and directories list that needs been ignored
set(CPACK_SOURCE_IGNORE_FILES "${PROJECT_BINARY_DIR};/.git/;.gitignore")

# Step 9: List of packaging generators for source code archives and binary archives
set(CPACK_SOURCE_GENERATOR "ZIP;TGZ")
set(CPACK_GENERATOR "ZIP;TGZ")

# Step 10: Now we can generating executable program on different platform
# For GNU/Linux:
# --------------
if(UNIX)
	if(CMAKE_SYSTEM_NAME MATCHES Linux)
		list(APPEND CPACK_GENERATOR "DEB")
		set(CPACK_DEBIAN_PACKAGE_MAINTAINER "nevergiu")
		set(CPACK_DEBIAN_PACKAGE_SECTION "devel")
		set(CPACK_DEBIAN_PACKAGE_DEPENDS "uuid-dev")

		list(APPEND CPACK_GENERATOR "RPM")
		set(CPACK_RPM_PACKAGE_RELEASE "1")
		set(CPACK_RPM_PACKAGE_LICENSE "GNU")
		set(CPACK_RPM_PACKAGE_REQUIRES "uuid-devel")
	endif()
endif()

# For Windows:
# ------------
if(WIN32 OR MINGW)
	list(APPEND CPACK_GENERATOR "NSIS")
	set(CPACK_NSIS_PACKAGE_NAME "message")
	set(CPACK_NSIS_CONTACT "nevergiu")
	set(CPACK_NSIS_ENABLE_UNINSTALL_BEFORE_INSTALL ON)
endif()

# For macOS:
# ----------
if(APPLE)
	list(APPEND CPACK_GENERATOR "Bundle")
	set(CPACK_BUNDLE_NAME "message")
	configure_file(${PROJECT_SOURCE_DIR}/cmake/Info.plist.inInfo.plist @ONLY)
	set(CPACK_BUNDEL_PLIST ${CMAKE_CURRENT_BINARY_DIR}/Info.plist)
	set(CPACK_BUNDLE_ICON ${PROJECT_SOURCE_DIR}/cmake/coffee.icns)
endif()

# Step 11: Usage current system generators to send an message for user
message(STATUS "CPack generators: ${CPACK_GENERATOR}")

# Step 12: Finally, we must include 'CPack.cmake' module.
include(CPack)
