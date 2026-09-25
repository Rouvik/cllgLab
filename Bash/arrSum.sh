#!/usr/bin/bash

read -p 'Enter arr: ' -a numbers

getSum()
{
	local sum=0
	for i in "$@"; do
		sum=$((sum + i))
	done

	echo $sum
}

getSum "${numbers[@]}"
