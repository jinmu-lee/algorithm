#!/bin/bash

name="linux"
course="expert"

# "linux expert"
var="$name $course"
echo $var

# "$linux \expert"
var="\$$name \\$course"
echo $var

# "$linux \\expert"
var="\$$name \\\\$course"
echo $var

# "experted linux"
var="${course}ed $name"
echo $var

# "linux_expert_170101"
var="${name}_${course}_'date +%y%m%d'"
echo $var
