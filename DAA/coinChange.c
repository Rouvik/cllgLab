#include <stdio.h>

#define ARRSIZE(arr) (sizeof(arr) / sizeof(arr[0]))

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

void bsort(int *arr, int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < n - i - 1; j++)
		{
			if(arr[j] < arr[j + 1])
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
	int n;
	printf("Enter n: ");
	scanf("%d", &n);
	int CHANGE[n];

	printf("Enter %d elems: ", n);
	for(int i = 0; i < n; i++) scanf("%d", &CHANGE[i]);

	bsort(CHANGE, n);

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
