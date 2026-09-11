#!/usr/bin/bash

read -p "Create students file? " cr_std_fl

if [ $cr_std_fl == 'y' ]; then
	rm -f students.txt

	while true; do
		read -p "Enter roll no, name and city (Ctrl + D to stop): " roll name city
		if [ -z "$roll" ]; then
			break
		fi

		printf "%s %s %s\n" "$roll" "$name" "$city" >> students.txt
	done
	sort -no students.txt students.txt
fi

printf "Enter choice ::\n1 = display contents\n2 = Display student info\n3 = Delete student\n4 = Add new entry\n5 = Update student\n> "
read ch

case "$ch" in

	1)
		cat students.txt
	;;

	2)
		read -p "Enter roll: " roll
		grep "$roll " students.txt
	;;

	3)
		read -p "Enter roll: " roll
		sed -i "/$roll/d" students.txt
	;;

	4)
		read -p "Enter roll no, name and city: " roll name city
		printf "%s %s %s\n" "$roll" "$name" "$city"  >> students.txt
		sort -no students.txt students.txt
	;;

	5)
		read -p "Enter roll no, name and city: " roll name city
		sed -i "/$roll/d" students.txt
		printf "%s %s %s\n" "$roll" "$name" "$city"  >> students.txt
		sort -no students.txt students.txt
	;;

	*)
		echo "Unknown choice"
	;;
esac

