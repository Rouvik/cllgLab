#include <stdio.h>
#include "rtbench.h"

#define ARRSIZE(arr) sizeof(arr) / sizeof(arr[0])

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int *arr, int low, int high)
{
	int pivot = arr[(low + high) / 2];
	int i = low - 1, j = high + 1;

	while (1)
	{
		do
		{
			i++;
		} while (arr[i] < pivot);

		do
		{
			j--;
		} while (arr[j] > pivot);

		if (i >= j)
			return j;

		swap(&arr[i], &arr[j]);
	}
}

void rqsort(int *arr, int low, int high)
{
	if (low < high)
	{
		int pind = partition(arr, low, high);

		rqsort(arr, low, pind);
		rqsort(arr, pind + 1, high);
	}
}

int main()
{
	BENCH(10, 100000, n *= 10)
	{
		int arr[n];
		genRandArr(arr, n, 100);

		MEASURE_T()
		{
			rqsort(arr, 0, n);
		}

		PRINT_MEASURE();
	}

	return 0;
}
