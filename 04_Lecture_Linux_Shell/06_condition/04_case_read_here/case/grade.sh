#/bin/bash

case $1 in 
[6-9][0-9] | 100)
	GRADE="P"
	;;
[0-9] | [1-5][0-9])
	GRADE="F"
	;;
*)
	GRADE="X"
	;;
esac
echo $GRADE
