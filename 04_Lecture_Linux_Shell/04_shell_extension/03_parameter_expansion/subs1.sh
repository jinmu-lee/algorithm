#!/bin/bash

var1=$1
var2=$2
[ $var1 = "aaa" ] && \
(
    [ $var2 = "bbb" ] && exit 1
    var2="xxx"
    echo subshell: var1=$var1 var2=$var2
)
echo var1=$var1 var2=$var2

#var1 aaa var2 bbb : exit
#var1=aaa var2=bbb 

#var1 bbb var2 ddd
#var1=bbb var2=ddd

#var1 aaa var2 ccc
#subshell: var1=aaa var2=xxx
#block: var1=aaa var2=xxx
#var1=aaa var2=ccc
