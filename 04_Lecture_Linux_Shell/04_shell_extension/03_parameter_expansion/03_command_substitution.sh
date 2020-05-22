#!/bin/bash

echo 'ls /etc | grep conf'
echo $(ls /etc | grep conf)

var=name_'date +%F'
echo $var

var=name_$(date +%F)
echo $var
