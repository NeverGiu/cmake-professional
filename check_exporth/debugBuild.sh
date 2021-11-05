#!/bin/bash
# filename debugBuild.sh

# Cache required paths
# --------------------
readonly rootDir=`pwd`
readonly buildDir="$rootDir/build"
readonly sourceDir="$rootDir/source"

readonly logPath="$rootDir/log"
readonly mainCmakePath="$rootDir/CMakeLists.txt"
readonly srcCmakePath="$sourceDir/CMakeLists.txt"

if [ ! -f $logPath ]
then
	touch $logPath
fi

if [ -d $buildDir ] && [ -f $srcCmakePath ] && [ -f $mainCmakePath ]
then
	cd $buildDir

	cmake -G Ninja -D CMAKE_BUILD_TYPE=Debug ..
	cmake --build . --config Debug
else
	if [ -f $logPath ]
	then
		currentTime=`date '+%F %T'`
		echo "Error: Cmake build(debug version) is interrupted..Please check." >> $logPath
		exit 0
	fi
fi

exit 0
