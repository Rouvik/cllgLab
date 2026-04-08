#include <stdio.h>
#include <time.h>

#include "helper.h"

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
	sort(arr, length);
	printf("After sort: ");
	printArr(arr, length);
	putchar('\n');

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

	return ERROR_VAL;
}

void test()
{
	
}

int main()
{
	int n;
	printf("Enter size of array: ");
	scanf("%d", &n);

	int arr[n];

	printf("Enter %d elements: ", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
	}

	int tgt;
	printf("Enter an element to search: ");
	while (getchar() != '\n')
		;
	scanf("%d", &tgt);

	clock_t st = clock();

	int index = rbsearch(arr, n, tgt);

	clock_t end = clock();

	if (index == ERROR_VAL)
	{
		printf("Failed to find %d\n", tgt);
	}
	else
	{
		printf("Found %d at %d\n", tgt, index);
	}

	printf("Time: %ld ticks\n", end - st);

	return 0;
}
