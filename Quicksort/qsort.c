#include <stdio.h>

#define ARRSIZE(arr) sizeof(arr) / sizeof(arr[0])

void printArr(int *arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}

	putchar('\n');
}

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

void qsort(int *arr, int low, int high)
{
	if (low < high)
	{
		int pind = partition(arr, low, high);

		qsort(arr, low, pind);
		qsort(arr, pind + 1, high);
	}
}

int main()
{
	int arr[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};

	printf("Before sorting: ");
	printArr(arr, ARRSIZE(arr));
	
	qsort(arr, 0, ARRSIZE(arr) - 1);
	
	printf("After sorting: ");
	printArr(arr, ARRSIZE(arr));

	return 0;
}
