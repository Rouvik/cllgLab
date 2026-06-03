#include <stdio.h>
#include <string.h>
#include <limits.h>

void printMat(int *mat, int rows, int cols)
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			printf("%d\t", mat[rows * i + j]);
		}
		putchar('\n');
	}
}

int main()
{
	int n;
	printf("Enter n matrices: ");
	scanf("%d", &n);

	int p[n + 1];

	printf("Enter dimentions of matrices:\n");
	for(int i = 0; i < 2 * n; i++)
	{
		scanf("%d", &p[(i + 1) / 2]);
	}

	int m[n][n];
	int k[n][n];

	memset(m, 0, sizeof(int) * n * n);
	memset(k, 0, sizeof(int) * n * n);

	for(int i = 0; i < n; i++)
	{
		for(int j = i; j < n; j++)
		{
			if(i == j) continue;

			int minVal = INT_MAX, minK = 0;
			for(int k = i + 1; k <= j; k++)
			{
				int val = m[i][k - 1] + m[k][j] + p[i] * p[k] * p[j + 1];

				if(minVal > val)
				{
					minVal = val;
					minK = k;
				}
			}

			m[i][j] = minVal;
			m[j][i] = minVal;
			k[i][j] = minK;
		}
	}

	printf("M:\n");
	printMat((int *) m, n, n);

	printf("\nK:\n");
	printMat((int *) k, n, n);

	return 0;
}
