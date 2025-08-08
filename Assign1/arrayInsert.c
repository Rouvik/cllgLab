#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "helper.h"

#define MAX_SIZE 10

void insertAtEnd(int *arr, int *size, int capacity, int element)
{
	if(*size >= capacity)
	{
		puts("Error overflow");
		return;
	}
	
	arr[*size] = element;
	(*size)++;
}

int main()
{
	srand(time(NULL));	// hardcoded random seed
	int arr[MAX_SIZE];
	memset(arr, 0, sizeof(arr));
	for(int i = 0; i < 5; i++)
	{
		arr[i] = rand() % 100;
	}

	int size = 5;
	insertAtEnd(arr, &size, MAX_SIZE, 1234);
	
	printArr(arr, MAX_SIZE);
	return 0;
}
