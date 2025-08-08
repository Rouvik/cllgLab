#include <stdio.h>

#define ERROR_VAL -999

void printArr(int *arr, int length)
{
	for(int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
}
