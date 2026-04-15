#include <stdio.h>
#include <sys/resource.h>
#include <time.h>
#include <stdlib.h>

#include "rtbench.h"

void sort(int *arr, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}

int rbsearch(int *arr, int length, int target)
{
	int i = 0, j = length - 1;
	while (i <= j)
	{
		int mid = (i + j) / 2;
		if (arr[mid] == target)
			return mid;

		if (target < arr[mid])
		{
			j = mid - 1;
		}
		else
		{
			i = mid + 1;
		}
	}

	return -999;
}

void genRandSortArr(int *arr, int n, int range)
{
	srand(time(NULL));
	int x = 0;
	for (int i = 0; i < n; i++)
	{
		x += rand() % range;
		arr[i] = x;
	}
}

int main()
{
	int max_n;
	printf("Input max n: ");
	scanf("%d", &max_n);

	FILE *fp = fopen("./bench.csv", "w");

	// printf("i\t\tn\t\ttime\t\tmem\n");
	for (int n = 100000, i = 1; n <= max_n; n += 10000, i++)
	{
		// int arr[n];
		int *arr = malloc(sizeof(int) * n);
		genRandSortArr(arr, n, 10);
		// genRandArr(arr, n, 100);

		int rand_elem = arr[rand() % n];

		clock_t st = clock();

		// sort(arr, n);
		int index = rbsearch(arr, n, rand_elem);

		clock_t end = clock();

		if (arr[index] != rand_elem)
		{
			printf("Fatal error search mismatch: %d %d %d\n", index, arr[index], rand_elem);
		}

		free(arr);

		// struct rusage usage;
		// getrusage(RUSAGE_SELF, &usage);

		// printf("%d\t\t%d\t\t%f\t%ld\n", i, n, (double)(end - st) / CLOCKS_PER_SEC, usage.ru_maxrss);
		fprintf(fp, "%d,%f\n", n, (double)(end - st) / CLOCKS_PER_SEC);
	}

	fclose(fp);

	return 0;
}
