#!/bin/bash

read line
echo $line | awk 'BEGIN {FS="-"} {print  "/home/user/myfile_" substr($1,3,4)$2$3}' |  awk 'BEGIN {FS=" "} {print $1$2 }' |  awk 'BEGIN {FS=":"} {print $1$2$3 ".bak" }' 
