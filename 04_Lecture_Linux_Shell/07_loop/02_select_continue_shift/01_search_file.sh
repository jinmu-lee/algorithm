#!/bin/bash

# ls -t -> modified time

cnt=0
for fname in `ls -t $1`
do
	if [ ! -f "$1/$fname" ]; then continue; fi
	echo $fname
	let cnt++
	if [ $cnt -eq $2 ]
	then
		break
	fi
done

cnt=0
for fname in `ls -t $1`
do
	if [ ! -f "$1/$fname" ]; then continue; fi
	let cnt++
	if [ $cnt -gt $2 ]
	then
		break
	fi
	echo $fname
done

