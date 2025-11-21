#include <stdio.h>

#define ARRSIZE(arr) sizeof(arr) / sizeof(arr[0])

void printArr(int *arr, int length)
{
	for(int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}

	putchar('\n');
}

int partition(int *arr, int length)
{
	if(length < 2) return 0;

	printf("DBG partition %d %d\n", arr[0], length);

	int i = 1, j = length - 1;
	for(; i <= j;)
	{
		for(; arr[i] < arr[0] && i <= j; i++);
		for(; arr[j] > arr[0] && i <= j; j--);

		int t = arr[i];
		arr[i] = arr[j];
		arr[j] = t;
	}

	int t = arr[j];
	arr[j] = arr[0];
	arr[0] = t;

	printArr(arr, length);

	return j;
}

void qsort(int *arr, int length)
{
	printf("DBG qsort\n");

	if(length == 1) return;

	int pind = partition(arr, length);

	qsort(arr, pind);
	qsort(arr + pind, length - pind);
}

int main()
{
	int arr[] = {1, 3, 2};

	qsort(arr, ARRSIZE(arr));

	for(int i = 0; i < ARRSIZE(arr); i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
