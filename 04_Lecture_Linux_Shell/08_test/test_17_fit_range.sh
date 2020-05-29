#!/bin/bash

read num
case $num in 
[0-9] | [0-9][0-9] | 100)
	GRADE="OK"
	;;
*)
	GRADE="X"
;;
esac
echo $GRADE
