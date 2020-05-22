#!/bin/bash

echo $1 | sed -nr '/^01[016-9]( |-|:)[0-9]{3,4}\1[0-9]{4,4}$/s/( |-|:)/ /gp' > /dev/null;
res=$(echo $?)
echo $res
if [ $res -eq 0 ]
then
	echo $1
else
	echo "wrong number"
fi

#echo ${res}:-"wrong number"
#res='echo $1 | sed -nr '/^01[016-9]( |-|:)[0-9]{3,4}\1[0-9]{4,4}$/s/( |-|:)/ /gp''
#echo ${res:-"wrong number"}

#echo $1|grep -E '^01[016-9]-[0-9]{3,4}-[0-9]{4,4}$' > /dev/null; echo $?

#help $1 | sed -n '/^*Options:/,/^*$/p' | sed '$d'
#help $1 | sed -n '/^ *Options:/,/^ *$/p' | sed '$d'
#help $1 | sed -n '/^ *Options:/,/^ *$/p' | sed '/^ *$/d'

#

#sed -n 's/bash$/mybash/p' /etc/passwd
#sed 's/^/<</' /etc/passwd
#sed 's/$/>>/' /etc/passwd
#sed 's/$/ >>/' /etc/passwd
#sed -n '/^root/s/bash/sh/p' /etc/passwd
#sed -n 's/^s[a-p]/my&/p' /etc/passwd
#sed -n '/root/,/dev/p' /etc/passwd
#sed -n '2,/dev/p' /etc/passwd
#sed 's/^/<</' /etc/passwd
#sed 's/^/ <</' /etc/passwd
#sed 's/^/ << /' /etc/passwd
#sed 's/^/ << / /s/$/ >> /' /etc/passwd
#sed -e 's/^/ << / /s/$/ >> /' /etc/passwd
#sed -e 's/^/ << /' -e '/s/$/ >> /' /etc/passwd
#sed -e 's/&/ >> /' -e '/s/^/ << /' /etc/passwd
#sed -e 's/$/ >> /' -e '/s/^/ << /' /etc/passwd
#sed -e 's/$/>>/' -e '/s/^/<</' /etc/passwd
#sed 's/$/>>/' -e '/s/^/<</' /etc/passwd
#sed -e 's/$/>>/' -e 's/^/<</' /etc/passwd
#sed -e 's/$/>>/' -e 's/^/<</' /etc/passwd
#sed -e 's/$/ >> /' -e 's/^/ << /' /etc/passwd
#sed -e '2,4d' -e 's/^sys/s../' -e 's/bash$/...h/' /etc/passwd

#ls -al $1 | sed -e '/^-/s/$/*/' -e '/^d/s/$/\//' -e '/^l/s/$/@/'
