#!/bin/bash

read word

dir=${word%/*}
name=${word##*/}
echo "dir="${dir}" name="${name}
