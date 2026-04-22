#include <stdio.h>
#include <time.h>

#define RTBENCH_IMPLEMENTATION
#include "rtbench.h"

void sort(int *arr, int length)
{
	for (int i = 0; i < length; i++)
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
	int i = 0, j = length - 1, mid;

	BENCH_STACK_MSR();

	while (i <= j)
	{
		mid = (i + j) / 2;
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

int main()
{
	FILE *fp = fopen("./bench.csv", "w");
	
	const int max_n = 10000;

	int arr[max_n];
	genRandSortedArr(arr, max_n, 100);


	BENCH(10, max_n, n += 10)
	{
		// genRandArr(arr, n, 100);

		int rand_elem = arr[rand() % n];

		int index;

		BENCH_STACK_PROBE();
		MEASURE_T(200, x)
		{
			// sort(arr, n);
			index = rbsearch(arr, n, rand_elem);
		}
			
		if (arr[index] != rand_elem)
		{
			printf("Fatal error search mismatch: %d %d %d\n", index, arr[index], rand_elem);
		}

		// PRINT_MEASURE(x);
		fprintf(fp, "%d,%ld,%ld\n", n, measure_time_x, BENCH_STACK_HIGH - BENCH_STACK_LOW);
	}

	fclose(fp);

	return 0;
}
