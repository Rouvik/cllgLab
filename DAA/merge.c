#include <stdio.h>
#include <sys/resource.h>

#include "rtbench.h"

void merge(int *arr1, int l1, int *arr2, int l2, int *dest)
{
	int i = 0, j = 0, k = 0;
	for (; i < l1 && j < l2;)
	{
		if (arr1[i] < arr2[j])
		{
			dest[k] = arr1[i++];
		}
		else
		{
			dest[k] = arr2[j++];
		}
		k++;
	}

	for (; i < l1; i++, k++)
	{
		dest[k] = arr1[i];
	}

	for (; j < l2; j++, k++)
	{
		dest[k] = arr2[j];
	}
}

void msort(int *arr, int length, int *dest)
{
	if (length == 1)
	{
		dest[0] = arr[0];
		return;
	}

	int mid = length / 2;

	int d1[mid];
	int d2[length - mid];
	msort(arr, mid, d1);
	msort(arr + mid, length - mid, d2);

	merge(d1, mid, d2, length - mid, dest);
}

int main(int argc, const char *argv[])
{
	BENCH(10, 100000, n *= 10)
	{
		int arr[n], dest[n];
		genRandArr(arr, n, 100);

		MEASURE_T()
		{
			msort(arr, n, dest);
		}

		struct rusage usage;
		getrusage(RUSAGE_SELF, &usage);

		printf("%d\t%d\t%ld\t%ld\n", i, n, measure_end_ - measure_st_, usage.ru_maxrss);
	}

	return 0;
}
