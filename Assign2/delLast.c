#include <stdio.h>

#include "helper.h"

int delLast(int *arr, int *size)
{
	if(*size == 0) return ERROR_VAL;

	return arr[--(*size)];
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
	
	printf("Deleted: %d\nAfter array: ", delLast(arr, &size));
	printArr(arr, size);
	putchar('\n');
	
	return 0;
}
