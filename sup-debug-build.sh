#!/bin/bash
# filename debugBuild.sh

# Cache required paths
# --------------------
readonly rootDir=`pwd`
readonly buildDir="$rootDir/build"
readonly srcDir="$rootDir/src"

readonly logPath="$rootDir/log"
readonly mainCmakePath="$rootDir/CMakeLists.txt"
readonly srcCmakePath="$srcDir/CMakeLists.txt"

if [ ! -f $logPath ]
then
	touch $logPath
fi

if [ ! -d $buildDir ]
then
	mkdir -p $buildDir
fi

if [ -d $buildDir ] && [ -f $srcCmakePath ] && [ -f $mainCmakePath ]
then
	cd $buildDir

	cmake -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=$HOME/TestApp/sup-install-build ..
	cmake --build . --target install
	# ctest -v
	# ninja test -v
	# ctest --output-on-failure -L foo --repeat-until-fail 3
	# ctest --output-on-failure
	# Run others except 'barTest', Run just 'fooTest' #
	# ctest -E 'barTest' -R 'fooTest'
	
else
	if [ -f $logPath ]
	then
		currentTime=`date '+%F %T'`
		echo "Error: Cmake build(debug version) is interrupted..Please check." >> $logPath
		exit 0
	fi
fi

exit 0
