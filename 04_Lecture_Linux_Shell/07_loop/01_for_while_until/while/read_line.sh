#!/bin/bash

cat $1 |
{
cnt=0
while read line
do
	echo "$line"
	let cnt++;
	echo $cnt
done
echo $cnt
}
