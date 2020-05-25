#!/bin/bash

count=0
while [ $count -lt 5 ]
do
	echo $count
	let count++
done

while true
do
	echo sleeping!
	sleep 1
done
