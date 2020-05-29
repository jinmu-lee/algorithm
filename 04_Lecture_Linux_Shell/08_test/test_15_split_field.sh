#!/bin/bash

read N

for x in `eval echo {1..$N}`
do
	read var
	echo $var | awk 'BEGIN {FS=":"} {print $1}'
done
