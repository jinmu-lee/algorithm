#!/bin/bash

SAFE=
is_safe ()
{
	len=${#1}
	if [ $len -lt 8 ]
	then
		SAFE=0
	else
		echo $1 | grep '[0-9]' | grep '[~!@#$%^&*]' | grep '[A-Z]' > /dev/null 2>&1
		[ $? -eq 0 ] && SAFE=1 || SAFE=0
	fi
}
is_safe "$1"
[ $SAFE -eq 1 ] && echo "YES" || echo "NO"
