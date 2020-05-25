#!/bin/bash

min=$1
max=$2
((var = max-min+1))
echo "random number is $((RANDOM%var+min))"


