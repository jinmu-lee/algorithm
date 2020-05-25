#!/bin/bash

num=0
while read line
do
	name=$( echo $line | cut -d ":" -f1 )
	let num++;
	echo "#$num: $name"
done < /etc/passwd

if false
then
cat /etc/passwd |
{
	num=0
	while read line
	do
		name=$( echo $line | cut -d ":" -f1 )
		let num++;
		echo "#$num: $name"
	done
}
fi
cat /etc/passwd | awk 'BEGIN { FS=":" }{ print "#" NR ":" $1 }'
