#!/bin/bash

# print any directory
func ()
{
	echo '$#' : $#
	echo '$0' : $0
	echo '$1' : $1
	echo '$2' : $2
	echo '$3' : $3
}

func one two three
