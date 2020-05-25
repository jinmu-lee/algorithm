#!/bin/bash

in_file=$1
out_file=${in_file}.info
type=$(file $in_file)

#./file_info.sh testfile
# in_file=testfile
# out_file=testfile.info
# type=	
cat > $out_file << INFO
Name: $in_file
Size: $(ls -l $in_file | awk '{print $5}')
Type : ${type#*: }
INFO
		
