def enterMat(dimx, dimy):
	print("Input a matrix:")
	mat = []
	for i in range(dimy):
		mat.append([*map(int, input().split())][:dimx])
	return mat

if __name__ == "__main__":
	dims = [*map(int, input("Enter dimentions x and y: ").split())]
	mat1 = enterMat(*dims)
	mat2 = enterMat(*dims)

	mat3 = []

	for i in range(dims[1]):
		mat3.append([])
		for j in range(dims[0]):
			mat3[i].append(mat1[i][j] + mat2[i][j])
	print(mat3)

