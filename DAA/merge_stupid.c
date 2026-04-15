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
	int max_n;
	printf("Enter max n: ");
	scanf("%d", &max_n);

	printf("i\tn\ttime\t\tmem\n");
	for (int n = 10, i = 1; n <= max_n; n *= 10, i++)
	{
		int arr[n], dest[n];
		genRandArr(arr, n, 100);
		
		clock_t st = clock();
		
		msort(arr, n, dest);
		
		clock_t end = clock();
		
		struct rusage usage;
		getrusage(RUSAGE_SELF, &usage);

		printf("%d\t%d\t%f\t%ld\n", i, n, (double)(end - st) / CLOCKS_PER_SEC, usage.ru_maxrss);
	}

	return 0;
}
