#!/usr/bin/bash

printf "Enter filename: "
read fname

if [ ! -f "$fname" ]; then
	echo "Error file is missing"
	exit 1
fi

printf "Enter starting line: "
read stl

printf "Enter number of lines: "
read nl


cat "$fname" | tail -n +"$stl" | head -n "$nl"
