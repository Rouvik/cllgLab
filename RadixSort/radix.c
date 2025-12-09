#include <stdio.h>
#include <math.h>
#include <string.h>

#define ARR_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

int maxLen(int *arr, int length)
{
	int m = 0;
	for(int i = 0; i < length; i++)
	{
		int x = ceil(log10(arr[i]));
		if(x > m) m = x;
	}

	return m;
}

void countSort(int *arr, int n, int exp)
{
	int count[10];
	memset(count, 0, 10 * sizeof(int));

	int output[n];

	for(int i = 0; i < n; i++)
	{
		count[(arr[i] / exp) % 10]++;
	}

	for(int i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	for(int i = n - 1; i >= 0; i--)
	{
		int ci = (arr[i] / exp) % 10;
		output[count[ci] - 1] = arr[i];
		count[ci]--;
	}

	memcpy(arr, output, n * sizeof(int));
}

void radixSort(int *arr, int length)
{
	int n = maxLen(arr, length);

	int r = 1;
	for(int i = 0; i < n; i++)
	{
		countSort(arr, length, r);
		r *= 10;
	}
}

void printArr(int *arr, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	putchar('\n');
}

int main(int argc, const char *argv[])
{
	int arr[10];
	printf("Enter 10 elements:\n");
	for(int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}

	radixSort(arr, 10);

	printf("Sorted: ");
	printArr(arr, 10);
	return 0;
}
