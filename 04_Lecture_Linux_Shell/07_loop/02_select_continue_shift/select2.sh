#!/bin/bash

PS3="Select number : "
echo "Select a command to know where it is"

select CMD in ls vi sed exit
do
	echo "You selected $CMD ($REPLY)"
	case $CMD in
		exit)
			echo "Exiting"
			break
			;;
		*)
			echo "`which $CMD`"
			;;
	esac
done
