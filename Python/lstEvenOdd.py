l = [*map(int, input("Enter a list of numbers: ").split())]

i = 0
for j in range(len(l)):
	if l[j] % 2 == 0:
		t = l[i]
		l[i] = l[j]
		l[j] = t
		i += 1

print(f"Even list: {l[0:i]}\nOdd list: {l[i:]}")

