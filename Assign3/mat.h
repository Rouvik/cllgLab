#ifndef INCLUDED_MAT_H
#define INCLUDED_MAT_H

#include <stdio.h>

#define INDEX(mat, y, x) mat[mat[0] * y + x + 2]

void printMat(int *m)
{
	for(int i = 0; i < m[0]; i++)
	{
		for(int j = 0; j < m[1]; j++)
		{
			printf("%d ", INDEX(m, i, j));
		}
		putchar('\n');
	}
}

void inputMat(int *m)
{
	puts("Enter elements of matrix:");
	for(int i = 0; i < m[0]; i++)
	{
		for(int j = 0; j < m[1]; j++)
		{
			scanf("%d", &INDEX(m, i, j));
		}
	}
}

#endif // INCLUDED_MAT_H
