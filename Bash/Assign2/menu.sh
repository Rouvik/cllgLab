#!/usr/bin/bash

echo "Enter choice: 1 = merge files, 2 = search pattern ::"
read ch

case $ch in

	1)
		echo "Enter 2 file paths to merge and output file: "
		read f1 f2 fo

		cat "$f1" "$f2" > "$fo"
		echo "Files merged successfully!"
	;;

	2)
		echo "Enter a pattern to search and a file: "
		read pat file

		grep "$pat" "$file"
	;;
	*) echo "Invalid option" ;;
esac

