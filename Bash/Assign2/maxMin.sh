#!/usr/bin/bash

echo "Enter numbers: "
read -ra arr

max=${arr[0]}
min=${arr[0]}

echo ${#arr}

for (( i = 0; i < ${#arr[@]}; i++ )); do
	if [ ${arr[i]} -gt $max ]; then
		max=${arr[i]}
	fi

	if [ ${arr[i]} -lt $min ]; then
		min=${arr[i]}
	fi
done

echo "Max: $max Min: $min"
