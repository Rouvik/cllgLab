#include <stdio.h>
#include "mat.h"

void addMat(int *m1, int *m2)
{
	if(m1[0] != m2[0] || m1[1] != m2[1])
	{
		printf("[ADD ERROR] Dimention mismatch!\n");
		return;
	}

	for(int i = 0; i < m1[0]; i++)
	{
		for(int j = 0; j < m1[1]; j++)
		{
			INDEX(m1, i, j) += INDEX(m2, i, j);
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
