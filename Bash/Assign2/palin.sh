#!/usr/bin/bash

read -p 'Enter a string: ' str

if [ $str == $(echo "$str" | rev) ]; then
	echo "Palindrome"
else
	echo "Not palindrome"
fi
