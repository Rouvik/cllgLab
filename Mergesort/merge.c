#include <stdio.h>

void merge(int *arr1, int l1, int *arr2, int l2, int *dest)
{
	int i = 0, j = 0, k = 0;
	for(; i < l1 && j < l2;)
	{
		if(arr1[i] < arr2[j])
		{
			dest[k] = arr1[i++];
		}
		else
		{
			dest[k] = arr2[j++];
		}
		k++;
	}

	for(; i < l1; i++, k++)
	{
		dest[k] = arr1[i];
	}

	for(; j < l2; j++, k++)
	{
		dest[k] = arr2[j];
	}
}

void msort(int *arr, int length, int *dest)
{
	if(length == 1)
	{
		dest[0] = arr[0];
		return;
	}

	int mid = length / 2;

	int d1[mid];
	int d2[length - mid];
	msort(arr, mid, d1);
	msort(arr + mid, length - mid, d2);

	merge(d1, mid, d2, length - mid, dest);
}

void printArr(int *arr, int length)
{
	fputs("Arr: ", stdout);
	for(int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}

	putchar('\n');
}

int main(int argc, const char *argv[])
{
	int n;
	fputs("Enter length: ", stdout);
	scanf("%d", &n);

	int arr[n];
	puts("Enter elements of array:");
	for(int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
	}

	int dest[n];
	msort(arr, n, dest);

	puts("Sorted:");
	printArr(dest, n);
	return 0;
}
