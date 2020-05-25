#/bin/bash

ftp -n $1 << CMDS
user "$2" "$3"
put "$4"
bye
CMDS
