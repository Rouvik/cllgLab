#include <stdio.h>

#include "mat.h"

int traceMat(int *m)
{
	if(m[0] != m[1])
	{
		printf("[TRACE ERROR] Dimentions must be same for trace\n");
		return -999;
	}

	int tr = 0;
	for(int i = 0; i < m[0]; i++)
	{
		tr += INDEX(m, i, i);
	}
	return tr;
}

int main(int argc, const char *argv[])
{
	int x, y;
	printf("Enter dimentions of both matrices (y, x): ");
	scanf("%d %d", &y, &x);

	int m[y * x + 2];
	m[0] = y;
	m[1] = x;

	inputMat(m);

	printf("Trace: %d\n", traceMat(m));
	return 0;
}
