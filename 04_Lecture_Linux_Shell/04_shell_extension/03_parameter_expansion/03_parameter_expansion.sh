#!/bin/bash

# length of variable
var1="string1"
echo ${#var1}

# substitution
echo ${var2:-"string2"}
echo $var2

var2="defined"
echo ${var2:-"string2"}
echo $var2

echo ${var3:+"string3"}
echo $var3

var3="defined"
echo ${var3:+"string3"}
echo $var3

# replace
