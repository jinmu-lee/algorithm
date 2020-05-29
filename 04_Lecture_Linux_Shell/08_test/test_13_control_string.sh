#!/bin/bash

read word
echo $word | awk '/^/ {print substr($9,1,length($9)-1) " - owner: " $3 " group: user size : "$5}'
