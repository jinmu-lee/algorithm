#!/bin/bash

PS3="Your choice : "
echo "Select a command"

select CMD in ls vi sed
do
	echo "You selected $CMD ($REPLY)"
done
