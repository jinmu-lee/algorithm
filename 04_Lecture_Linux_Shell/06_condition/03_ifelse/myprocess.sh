#!/bin/bash

#jinmu.lee@ADAS-BSP:~/lec_linux_shell/06_condition/03_ifelse$ ps -C bash
#PID TTY          TIME CMD
#589 pts/18   00:00:00 bash
#1329 pts/19   00:00:00 bash
#6084 pts/17   00:00:00 bash
#18654 pts/20   00:00:00 bash
#31937 pts/22   00:00:00 bash
#32036 pts/2    00:00:01 bash
#jinmu.lee@ADAS-BSP:~/lec_linux_shell/06_condition/03_ifelse$ ps -C bash | sed '1d'
#589 pts/18   00:00:00 bash
#1329 pts/19   00:00:00 bash
#6084 pts/17   00:00:00 bash
#18654 pts/20   00:00:00 bash
#31937 pts/22   00:00:00 bash
#32036 pts/2    00:00:01 bash
#jinmu.lee@ADAS-BSP:~/lec_linux_shell/06_condition/03_ifelse$ ps -C bash | awk '{print $1}'
#PID
#589
#1329
#6084
#18654
#31937
#32036
#jinmu.lee@ADAS-BSP:~/lec_linux_shell/06_condition/03_ifelse$ ps -C bash | sed '1d' | awk '{print $1}'
#589
#1329
#6084
#18654
#31937
#32036


ps -C $1 > /dev/null 2>&1

if [ $? -eq 0 ]
then
	echo "It is running"
	ps -C $1 | sed '1d' | awk '{print $1}'
else
	echo "It is not running"
fi
