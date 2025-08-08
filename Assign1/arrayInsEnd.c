#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 10

#include "helper.h"

void insertAtStart(int *arr, int *size, int capacity, int element)
{
	if(*size >= capacity)
	{
		puts("Error overflow");
		return;
	}

	for(int i = *size; i > 0; i--)
	{
		arr[i] = arr[i - 1];
	}

	arr[0] = element;
	(*size)++;
}

int main()
{
	srand(time(NULL));

	int arr[MAX_SIZE];
	memset(arr, 0, sizeof(arr));

	int size = 5;
	for(int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}

	printArr(arr, MAX_SIZE);

	putchar('\n');

	insertAtStart(arr, &size, MAX_SIZE, 1234);

	printArr(arr, MAX_SIZE);
	return 0;
}
