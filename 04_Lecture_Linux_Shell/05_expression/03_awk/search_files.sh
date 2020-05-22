#!/bin/bash

#grep -Em '^#! ?/bin/(bash|sh)$' $1 2>/dev/null | awk 'BEGIN {FS=":"}{print $1}'>$2

#grep -Em '^#! ?/bin/(bash|sh)$' $1 2>/dev/null | awk 'BEGIN {FS=":"}{print $1":"$2}' | awk 'BEGIN {FS=":"} /:1$/ {print $1}'>$2

grep -Ern '^#! ?/bin/{bash|sh}$' /etc 2>/dev/null | awk 'BEGIN {FS=":"} { print $1 }' > aaa.log
grep -Ern '^#! ?/bin/{bash|sh}$' /etc 2>/dev/null | awk 'BEGIN {FS=":"} { print $1":"$2 }' | awk 'BEGIN {FS=":"} /:1$/ {print $1}'  > aaa.log
