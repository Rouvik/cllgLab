#!/usr/bin/bash

for(( i = 1; i <= 20; i++ )); do
	read prof sub loc
	printf "T%03d|%s|%s|%s\n" $i $prof $sub $loc >> file.txt
done
