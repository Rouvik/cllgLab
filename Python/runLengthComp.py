# Example string AAAABBBBBCCD
# Example output: A4B5C2D1

inp = input("Enter a string to compress: ")
ch = inp[0]
i = 0
count = 0
while i < len(inp):
	if inp[i] == ch:
		count += 1
	else:
		print(ch, count, sep='', end='')
		count = 1
		ch = inp[i]
	i += 1

print(ch, count, sep='') # Waste a new line to make it terminal friendly
