#!/bin/bash

var=75

test $var -gt 100
echo $?

[ $var -gt 50 ] 
echo $?
