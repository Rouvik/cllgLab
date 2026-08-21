#!/usr/bin/bash

# a)
printf 'a)\n'
head -3 Teachers

# b)
printf '\nb)\n'
ls -l -t | tail -1
# Explanation: Gets the list of files in long form (-l) sorted in modified time order (-t) and then extracts the last line from output (tail -1)

# c)
printf '\nc)\n'
head -c 100 Teachers

# d)
printf '\nd)\n'
tail -3 Teachers

# e)
printf '\ne)\n'
tail -n +5 Teachers

# f)
printf '\nf)\n'
head -5 Teachers | tee Shortlist

# g)
printf '\ng)\n'
cut -d'|' -f2,4 Shortlist | tr '|' ' '

# h)
printf '\nh)\n'
cut -d'|' -f3 Shortlist | tee Cutlist1

# i)
printf '\ni)\n'
cut -d'|' -f1,2,4 Shortlist > Cutlist2

# j)
printf '\nj)\n'
paste Cutlist1 Cutlist2

# k)
printf '\nk)\n'
sort -k2 -t'|' Teachers

# l)
printf '\nl)\n'
sort -r Teachers

# m)
# No 'sort numfile' expects the items to be sorted to be present seperated by newlines (\n) or by NULL (\0) using the -z flag, hence direct sorting will fail

printf '\nb)\nNo sort numfile expects the items to be sorted to be present seperated by newlines (\\n) or by NULL (\\0) using the -z flag, hence direct sorting will fail\n'

# n)
printf '\nn)\n'
sed 's/|/n/g' Teachers | tr 'a-z' 'A-Z'

# o)
printf '\no)\n'
grep 'container' Teachers


# p)
printf '\np)\n'
grep -o 'Howrah' Teachers | wc -l

# q)
printf '\nq)\n'
grep -n "Jadavpur" Teachers
