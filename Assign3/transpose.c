#include <stdio.h>

#include "mat.h"

void transposeMat(int *src, int *dest)
{
	if (src[0] != dest[0] || src[1] != dest[1])
	{
		printf("Error cannot transpose matrix, destination dimentions mismatch: %d x %d vs %d vs %d\n", src[0], src[1], dest[0], dest[1]);
		return;
	}
	
	for (int i = 0; i < src[0]; i++)
	{
		for (int j = 0; j < src[1]; j++)
		{
			INDEX(dest, j, i) = INDEX(src, i, j);
		}
	}
}

int main(int argc, const char *argv[])
{
	int x, y;
	printf("Enter dimentions of both matrices (y, x): ");
	scanf("%d %d", &y, &x);

	int m1[y * x + 2];
	m1[0] = y;
	m1[1] = x;
	inputMat(m1);

	int m2[y * x + 2];
	m2[0] = x;
	m2[1] = y;

	transposeMat(m1, m2);

	puts("Transpose:");
	printMat(m2);

	return 0;
}
