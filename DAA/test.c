#include <stdio.h>

#include "helper.h"

int main()
{
	int arr[64];
	genRandArr(arr, 64, 100);
	printArr(arr, 64);

	return 0;
}
