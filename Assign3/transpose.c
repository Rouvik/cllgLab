#include <stdio.h>

#include "mat.h"

tbvyh

int main(int argc, const char *argv[])
{
	int x, y;
	printf("Enter dimentions of both matrices (y, x): ");
	scanf("%d %d", &y, &x);

	int m1[y * x + 2];
	m1[0] = y;
	m1[1] = x;

	int m2[y * x + 2];
	m2[0] = y;
	m2[1] = x;

	inputMat(m1);
	inputMat(m2);

	addMat(m1, m2);

	puts("Sum:");
	printMat(m1);

	return 0;
}
