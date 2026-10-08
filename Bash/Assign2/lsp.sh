#!/usr/bin/bash

read -p "Enter filename: " fname

if [ ! -f "$fname" ]; then
	echo "Error file is missing"
	exit 1
fi

read -p "Enter starting line: " stl

read -p "Enter number of lines: " nl

cat "$fname" | tail -n +"$stl" | head -n "$nl"
