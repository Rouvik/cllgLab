def sqList(x):
	for i in range(len(x)):
		x[i] = x[i] ** 2
		print("State: ", x)

if __name__ == "__main__":
	lst =[*map(int, input("Enter a list of numbers: ").split())]
	sqList(lst)
