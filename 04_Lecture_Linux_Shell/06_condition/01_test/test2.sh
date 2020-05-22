#!/bin/bash

var=100

[ $var -gt 50 ] && echo "$var is greater than 50"

[ -n "$xxx" ] || echo "it is null"

file="/etc/issue"
[ -f $file ] && echo "$file exists" || echo "$file doesn't exist"

dir="/etc/xxx"
[ -d $dir ] && echo "$dir exists" || echo "$dir doesn't exist"
