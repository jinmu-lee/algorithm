#!/bin/bash

SAFE=0
is_safe ()
{
	len=${#1}
	if [ $len -lt 8 ]
	then
		SAFE=0
	else
		out=
		res=`eval echo $1 | grep '[0-9]' | grep '[~!@#$%^&*]' | grep '[A-Z]' | echo >&2 $out`
		echo $out
		[ $out -eq 1 ] && SAFE=1 || SAFE=0
	fi
}
read line
is_safe "$line"
[ $SAFE -eq 1 ] && echo "YES" || echo "NO"

