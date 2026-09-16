#!/usr/bin/bash

read -p "Enter a string: " str

rev=""

for (( i = 0; i < ${#str}; i++ )); do
    rev="${str:i:1}$rev"
done

if [ "$rev" == "$str" ]; then
    echo "Palindrome"
else
    echo "Not palindrome"
fi