#ifndef HELPER_INC
#define HELPER_INC

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ERROR_VAL -999

void printArr(int *arr, int length)
{
	for(int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
}

void genRandArr(int *arr, int length, int range)
{
	struct timespec tm;
	if(clock_gettime(CLOCK_MONOTONIC, &tm))
	{
		perror("Clock");
	}

	srand(tm.tv_sec);
	for(int i = 0; i < length; i++)
	{
		arr[i] = rand() % range;
	}
}

#endif // HELPER_INC
