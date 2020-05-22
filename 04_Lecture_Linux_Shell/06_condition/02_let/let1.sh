#!/bin/bash

let var=10
let var=var+5
let "var = var + 5"
echo $?
let "var -= 20"
echo $?
