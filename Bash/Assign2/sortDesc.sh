#!/usr/bin/bash

echo "Enter some numbers to sort, press Ctrl + D to end: "

input=$(cat)

echo "Sorted output:"
echo "$input" | tr ' ' '\n' | sort -r -n
