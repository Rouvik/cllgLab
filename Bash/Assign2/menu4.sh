#!/usr/bin/bash

printf "Enter option ::\n1 = Number of presently active users\n2 = Display lines from top of a file\n3 = Updating access time of a given fileto current time\n > "

read ch

case $ch in
	1)
		printf "Presently active users: "; who | wc -l
	;;

	2)
		printf "Enter number of lines and a file path: "
		read n file

		head -n "$n" "$file"
	;;

	3)
		printf "Enter a file: "
		read fname

		touch -a "$fname"
	;;

	*) echo "Invalid choice";;
esac
