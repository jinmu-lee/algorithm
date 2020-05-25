#!/bin/bash

RET=
comp ()
{
	if [ $1 -gt 1024 ]
	then
		RET=$1
	else
		RET="SMALL"
	fi
}
comp 10
echo return is $RET
comp 100
echo return is $RET
