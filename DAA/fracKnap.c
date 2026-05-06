#include <stdio.h>

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int knap(int *price, int *size, int n, int knapSize)
{
	float totalPrice = 0;
	int leftSize = knapSize;
	float pps[n];
	for(int i = 0; i < n; i++)
	{
		pps[i] = (float)price[i] / size[i];
	}

	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < n - i - 1; j++)
		{
			if(pps[j] < pps[j + 1])
			{
				float t = pps[j];
				pps[j] = pps[j + 1];
				pps[j + 1] = t;

				swap(&price[j], &price[j + 1]);
				swap(&size[j], &size[j + 1]);
			}
		}
	}

	for(int i = 0; i < n && leftSize > 0; i++)
	{
		totalPrice += price[i] * (leftSize >= size[i] ? 1.0 : (float) leftSize / size[i]);
		leftSize -= size[i];
	}

	return totalPrice;
}

int main()
{
	int knapSize = 50;
	int size[5] = {10, 13, 7, 5, 2};
	int price[5] = {30, 50, 20, 90, 10};

	printf("Total: %d\n", knap(price, size, 5, knapSize));
	return 0;
}
