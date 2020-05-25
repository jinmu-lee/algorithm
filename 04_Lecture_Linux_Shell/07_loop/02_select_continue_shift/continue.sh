#!/bin/bash

for fname in /etc/*.conf
do
	fsize=`stat -c %s $fname`
	if [ $fsize -gt 1024 ]
	then
		continue
	fi
	echo "$fname $fsize"
done
