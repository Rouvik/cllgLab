#include <stdio.h>

#include "mat.h"

void matMul(int *m1, int *m2, int *m3)
{
	if(m1[1] != m2[0] || m1[0] != m3[0] || m2[1] != m3[1])
	{
		printf("[MAT ERROR] Dimention mismatch\n");
		return;
	}

	for(int i = 0; i < m1[0]; i++)
	{
		for(int j = 0; j < m2[1]; j++)
		{
			INDEX(m3, i, j) = 0;
			for(int k = 0; k < m1[1]; k++)
			{
				INDEX(m3, i, j) += INDEX(m1, i, k) * INDEX(m2, k, j);
			}
		}
	}
}

int main()
{
	int x, y;	
	printf("Enter dimentions of matrix (y, x): ");
	scanf("%d %d", &y, &x);

	int m1[y * x + 2];
	m1[0] = y;
	m1[1] = x;

	inputMat(m1);

	printf("Enter dimentions of matrix (y, x): ");
	scanf("%d %d", &y, &x);

	int m2[y * x + 2];
	m2[0] = y;
	m2[1] = x;

	inputMat(m2);

	int m3[m1[0] * m2[1] + 2];
	m3[0] = y;
	m3[1] = x;

	matMul(m1, m2, m3);

	puts("Output:");
	printMat(m3);
	return 0;
}
