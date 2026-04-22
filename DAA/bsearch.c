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

int main()
{
	BENCH(10, 100000, n *= 10)
	{
		int arr[n];
		genRandArr(arr, n, 100);

		int rand_elem = arr[rand() % n];

		int index;

		MEASURE_T(x)
		{
			sort(arr, n);
			index = rbsearch(arr, n, rand_elem);
		}
			
		if (arr[index] != rand_elem)
		{
			printf("Fatal error search mismatch: %d %d %d\n", index, arr[index], rand_elem);
		}

		PRINT_MEASURE(x);
	}

	return 0;
}
