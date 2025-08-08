#include <stdio.h>

#include "helper.h"

int delFirst(int *arr, int *size)
{
	int x = arr[0];

	for(int i = 1; i < *size; i++)
	{
		arr[i - 1] = arr[i];
	}
	
	(*size)--;
	return x;
}

int main(int argc, const char *argv[])
{
	int n;
	printf("Enter size: ");
	scanf("%d", &n);

	int arr[n];
	
	printf("Enter %d elements for array: ", n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
	}

	int size = n;

	printf("Before array: ");
	printArr(arr, size);
	
	printf("\nDeleted: %d\nAfter array: ", delFirst(arr, &size));
	printArr(arr, size);
	putchar('\n');
	
	return 0;
}
