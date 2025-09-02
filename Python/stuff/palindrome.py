x = input("Enter a string: ")

i, j = 0, len(x) - 1

while i <= j:
    if x[i] != x[j]:
        print(f"{x} is not palindrome")
        exit(0)
    i += 1
    j -= 1

print(f"{x} is palindrome")