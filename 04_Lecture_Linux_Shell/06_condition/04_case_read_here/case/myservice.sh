#/bin/bash

case $1 in 
start)
	echo "service started"
	;;
stop)
	echo "service stopped"
	;;
restart)
	echo "service restarted"
	;;
*)
	echo "Usage: $0 start|stop|restart"
	;;
esac
