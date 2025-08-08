#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#include "helper.h"

#define MAX_SIZE 10

void insertAt(int *arr, int *size, int capacity, int element, int index)
{
	if(*size >= capacity)
	{
		puts("Error overflow");
		return;
	}
	else if(index >= capacity)
	{
		puts("Illegal position out of bounds");
		return;
	}

	if(index >= *size)
	{
		arr[index] = element;
	}
	else
	{
		for(int i = *size; i > index; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[index] = element;
	}

	(*size)++;
}

int main()
{
	int arr[MAX_SIZE];
	memset(arr, 0, sizeof(arr));
	srand(time(NULL));

	int size = 8;

	for(int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}

	printArr(arr, MAX_SIZE);
	putchar('\n');

	insertAt(arr, &size, MAX_SIZE, 1234, 3);
	insertAt(arr, &size, MAX_SIZE, 4567, 9);

	printArr(arr, MAX_SIZE);
	putchar('\n');
	return 0;
}
