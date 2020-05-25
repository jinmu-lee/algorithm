#!/bin/bash

# stat -c %s /etc/issue
#size='stat -c %s $1'
#size=`stat -c %s $1`
size=`ls -l $1 | cut -d ' ' -f5`

if [ $size -gt 1024 ]
then
	echo "Greater than 1024 bytes"
else
	echo "below 1024 bytes"
fi
