#include <stdio.h>

void printArr(int *arr, int capacity)
{
	for(int i = 0; i < capacity; i++)
	{
		printf("%d ", arr[i]);
	}
}
