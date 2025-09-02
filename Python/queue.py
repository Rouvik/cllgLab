container = []

if __name__ == "__main__":
	while True:
		ch = int(input("Enter choice:\n1) Insert elem\n2) Remove elem\n3) Print\n4) Quit\n> "))
		match ch:
			case 1:
				elem = int(input("Enter an element to insert: "))
				container.insert(0, elem)
				print(container)

			case 2:
				elem = container.pop()
				print("Removed: ", elem)
				print(container)

			case 3:
				print("Container: ", container)

			case 4:
				break

			case _:
				print("Unknown case")
