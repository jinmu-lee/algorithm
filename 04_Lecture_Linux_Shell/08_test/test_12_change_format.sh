#!/bin/bash

read N
for x in `eval echo {1..$N}`
do
	read PH
	res=`echo $PH | sed -nr '/^01[016-9]( |-|:)[0-9]{3,4}\1[0-9]{4,4}$/s/( |-|:)/ /gp'`
	echo ${res:-"wrong number"}
done
