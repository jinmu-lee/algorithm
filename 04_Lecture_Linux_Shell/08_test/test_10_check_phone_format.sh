#!/bin/bash

read N

for x in `eval echo {1..$N}`
do
	read time 
	res=`echo $time | sed -nr '/^01[016-9](-)[0-9]{3,4}\1[0-9]{4,4}$/s/(-)/ /p'; echo $?`
#	res=`echo $?`
	if [ $res -eq 0 ]
	then
		echo "YES"
	else
		echo "NO"
	fi
done
