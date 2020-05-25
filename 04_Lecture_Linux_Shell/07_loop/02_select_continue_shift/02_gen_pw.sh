#!/bin/bash

ch=({{0..9},{a..z},{A..Z}})
len=${#ch[*]}

echo ${ch[*]} $len
pw=
for x in `eval echo {1..$1}`
do
	(( idx = RANDOM%len ))
	pw=${pw}${ch[idx]}
	echo $pw
done
echo $pw
