#!/bin/bash
# filename: buildCleaner.sh

# Cache required paths
# --------------------
readonly rootDir=`pwd`
readonly buildDir="$rootDir/build"

readonly logPath="$rootDir/log"

# Make sure file 'log' has been created
# -------------------------------------
if [ ! -f $logPath ]
then
	touch $logPath
fi

# Files cleaner
# -------------
if [ -d $buildDir ]
then
	cd $buildDir
	rm -rf *

	if [ -f $logPath ]
	then
		currentTime=`date '+%F %T'`
		echo "Files has been cleaned up($currentTime)." >> $logPath
	fi
else
	if [ -f $logPath ]
	then
		currentTime=`date '+%F %T'`
		echo "Error: Folder 'build' does not exist($currentTime)..Please check." >> $logPath
	fi
fi

exit 0
