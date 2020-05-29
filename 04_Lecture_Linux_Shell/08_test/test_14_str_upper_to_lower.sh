#!/bin/bash

read word

res=`echo $word | tr '[A-Z]' '[a-z]'`
echo $res
