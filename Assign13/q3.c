#include <stdio.h>
#include <stdlib.h>

void sort(int n, int *arr)
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < n - i - 1; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}

int main()
{
	printf("Enter number of elements: ");
	int n;
	scanf("%d", &n);

	int arr[n];
	for(int i = 0; i < n; i++)
	{
		printf("Enter %d element: ", i + 1);
		scanf("%d", &arr[i]);
	}

	sort(n, arr);

	puts("After sorting:");
	for(int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	putchar('\n');
	return 0;
}
