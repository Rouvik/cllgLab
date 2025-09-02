from collections import Counter

inp = input("Enter a string: ").lower()

count = Counter([*inp])

print("Element\tFrequency")
for i in sorted(count.items(), key=lambda elem: elem[0]):
	print(f"{i[0]}\t\t{i[1]}")
