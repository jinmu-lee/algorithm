#/bin/bash

TIMEOUT=3
echo -n "Enter your id: "
#echo "Enter your id: "
read ID

if [[ "$ID" == [0-9]* ]]
then
	echo "Invalid ID format"
	exit -1;
fi
echo -n "Enter your password: "
#echo "Enter your password: "
read -t $TIMEOUT PW

if [ -z "$PW" ]
then
	echo "Timt out!!!"
	exit -1
fi

echo "registered successfully"
echo "id: $ID, pw: $PW"
