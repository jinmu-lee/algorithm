#!/bin/bash

# print lines from 2 to 4
sed '2,4p' /etc/passwd
sed -n '2,4p' /etc/passwd
cat /etc/passwd | sed -n '2,4p'

# print lines including "root"
sed -n '/root/p' /etc/passwd
# print lines including "sys" at the beginning
sed -n '/^sys/p' /etc/passwd
# print lines including "bash" at the end
sed -n '/bash$/p' /etc/passwd

# delete line 2
sed '2d' /etc/passwd
# delete lines from 3 to end
sed '3,$d' /etc/passwd
# delete lines including "nologin"
sed '/nologin/d' /etc/passwd

# replace first "root" to "myroot"

