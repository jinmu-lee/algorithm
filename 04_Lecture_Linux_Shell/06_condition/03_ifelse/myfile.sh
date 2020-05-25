#!/bin/bash

FNAME=$1
if [ $# -ne 1 ]
then
	echo "usage $0 file_name"
	exit -1;
fi
if [ -d $FNAME ]
then
	echo "$FNAME is a directory"
else
	if [ -f $FNAME ]
	then
		echo "$FNAME is a file"
	else
		echo "$FNAME does not exist"
	fi
fi
