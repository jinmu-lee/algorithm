#/bin/bash
shopt -s nocasematch
case $1 in 
Alex)
	ID="ace988"
	;;
Sunny)
	ID="best4u"
	;;
*)
	ID="unknown"
	;;
esac
echo $ID
