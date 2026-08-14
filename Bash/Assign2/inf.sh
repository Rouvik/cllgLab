#!/usr/bin/bash

inf() {
	while true; do echo Inf; done
}

inf &
cpid1=$!
inf &
cpid2=$!

echo "Killing $cpid1"
kill $cpid1
echo "Killing $cpid2"
kill $cpid2
