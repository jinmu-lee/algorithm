#!/bin/bash

for fname in /etc/*.conf
do
	echo $fname
done

for num in 1 2 4
do
	echo $num
done

s=1
e=5
for count in `eval echo {$s..$e}`
do
	echo $count
done

for fname in `ls *.txt`
do
	echo $fname
done


