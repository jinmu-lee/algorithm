#!/bin/bash

cp $1 $2 > /dev/null 2>&1

if [ $? -eq 0 ]
then
	echo "Copy Success"
else
	echo "Copy Failed"
fi
