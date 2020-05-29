#!/bin/bash

read N

for x in `eval echo {1..$N}`
do
	read time 
	echo $time | sed -n '/^[0-2][0-4](:)[0-5][0-9](:)[0-5][0-9]$/,/^*$/p' > /dev/null
	res=$(echo $?)
	if [ $res -eq 0 ]
	then
		echo "YES"
	else
		echo "NO"
	fi
done
