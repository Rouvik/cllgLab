from collections import Counter

x = input("Enter a string: ")
counter = Counter(x)

for elem in counter.items():
    print(f"Character {elem[0]} is present {elem[1]} times")