#include <stdio.h>

#include "helper.h"

int search(int *arr, int capacity, int tgt)
{
	for(int i = 0; i < capacity; i++)
	{
		if(arr[i] == tgt) return i;
	}

	return -1;
}	

int main()
{
	int arr[10] = { 1, 3, 5, 2, 7, 8, 9, 3, 90, 123 };

	printArr(arr, 10);
	putchar('\n');

	int n;
	fputs("Enter a number: ", stdout);
	scanf("%d", &n);

	int index = search(arr, 10, n);

	printf("Found %d? %s Index is: %d\n", n, index != -1 ? "true" : "false", index);
	return 0;
}
