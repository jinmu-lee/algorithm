#!/bin/bash

max ()
{
	if [ $1 -gt $2 ]; then
		return $1
	else
		return $2
	fi
}
max $1 $2
echo "max is $?"
