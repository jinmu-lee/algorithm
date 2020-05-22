#!/bin/bash

echo $1|grep -E '^01[016-9]-[0-9]{3,4}-[0-9]{4,4}$' > /dev/null; echo $?
