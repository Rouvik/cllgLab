x = input("Enter a string: ")
y = input("Enter a substring: ")
index = x.find(y)

if index != -1:
    print(f"\"{y}\" is present in \"{x}\" at {index}")
else:
    print(f"\"{y}\" is NOT present in \"{x}\"")