#include <stdio.h>

#include "helper.h"

int delAny(int *arr, int *size, int index)
{
	if(index >= *size) return ERROR_VAL;

	int x = arr[index];

	for(int i = index + 1; i < *size; i++)
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
	
	int index;
	printf("\nEnter an index to delete from: ");
	scanf("%d", &index);
	
	printf("Deleted: %d\nAfter array: ", delAny(arr, &size, index));
	printArr(arr, size);
	putchar('\n');
	
	return 0;
}
