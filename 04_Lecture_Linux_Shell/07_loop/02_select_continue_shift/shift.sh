#!/bin/bash

if [ $# -eq 0 ]
#if (( $# == 0 ))
then
	echo "Usage: $0 cmd1 cmd2 ... cmdN"
fi


while [ $# -ne 0 ]
# while (( $# != 0 ))
do
	echo "$#" "$1" "`which $1`"
	shift
done
