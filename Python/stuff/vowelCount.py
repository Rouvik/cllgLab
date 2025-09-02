x = input("Enter a string: ")
vowels = "aeiouAEIOU"
count = 0
for ch in x:
    if vowels.find(ch) != -1:
        count += 1

print("Number of vowels: ", count)