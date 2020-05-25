#!/bin/bash

for infile in `ls $1/*.bin`
do
	#abc.bin abc.asc
	outfile=${infile%.*}.asc
	echo $outfile
	xxd $infile > $outfile
done
