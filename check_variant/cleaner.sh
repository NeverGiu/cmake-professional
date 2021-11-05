#!/bin/bash
# filename: cleaner.sh

# Cache Required Paths
# --------------------
readonly rootDir=`pwd`
readonly logPath="$rootDir/log"

# Log Creation
# ------------
if [ ! -f $logPath ]
then
	touch $logPath
fi

# Checking Creation Environment
# -----------------------------
items=`ls`
for item in $items
do
	if [ "$item" = "log" ] || [ "$item" = "cleaner.sh" ] || [ "$item" = "CMakeLists.txt" ]
	then
		continue
	else
		if [ -f $logPath ]
		then
			currentTime=`date '+%F %T'`
			echo "Debug: Deleting $item($currentTime)." >> $logPath
			rm -rf $item
		fi
	fi
done

exit 0
