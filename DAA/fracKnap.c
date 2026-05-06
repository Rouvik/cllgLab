#include <stdio.h>
#include <string.h>

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

float knap(int *price, int *size, float *fractions, int n, int knapSize)
{
	memset(fractions, 0, sizeof(float) * n);

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
		float fracn = (leftSize >= size[i] ? 1.0 : (float) leftSize / size[i]);
		fractions[i] = fracn;
		totalPrice += price[i] * fracn;
		leftSize -= size[i];
	}

	return totalPrice;
}

int main()
{
	int n, ks;
	printf("Enter number of choices and knapsack size: ");
	scanf("%d %d", &n, &ks);

	int price[n], size[n];
	float fraction[n];

	printf("Enter %d prices: ", n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &price[i]);
	}

	printf("Enter %d sizes: ", n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &size[i]);
	}

	float totalPrice = knap(price, size, fraction, n, ks);
	printf("Fractions: ");
	for(int i = 0; i < n; i++)
	{
		printf("%f ", fraction[i]);
	}

	printf("\nTotal: %f\n", totalPrice);
	return 0;
}
