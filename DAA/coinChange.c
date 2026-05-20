#include <stdio.h>
#include <stdlib.h>

void printArr(int *arr, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d\t", arr[i]);
	}
}

int coinChange(int *CHANGE, int *change, int n, int amount)
{
	for(int i = 0; i < n; i++)
	{
		change[i] = amount / CHANGE[i];
		amount %= CHANGE[i];
	}

	if(amount > 0)
		return 1;
	return 0;
}

int compare(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int main()
{
	int n;
	printf("Enter n: ");
	scanf("%d", &n);
	int CHANGE[n];

	printf("Enter %d elems: ", n);
	for(int i = 0; i < n; i++) scanf("%d", &CHANGE[i]);

	qsort(CHANGE, n, sizeof(int), compare);

	int arr[n];
	int amount;
	while(1)
	{
		printf("Enter amount (0 to exit): ");
		scanf("%d", &amount);

		if(amount <= 0) return 0;

		if(coinChange(CHANGE, arr, n, amount))
		{
			printf("Error failed to solve\n");
			continue;
		}

		printf("Change:\n");
		printArr(CHANGE, n);
		printf("\nCoins:\n");
		printArr(arr, n);
		putchar('\n');
	}
	return 0;
}
