#include <stdio.h>

int factSum(int n)
{
	int sum = 0;
	for(int i = 1; i < n; i++)
	{
		if(n % i == 0)
		{
			sum += i;
		}
	}
	return sum;
}

int main()
{
	for(int i = 2; i < 10000; i++)
	{
		int amicablePair = factSum(i);
		if(amicablePair > i && factSum(amicablePair) == i)
		{
			printf("Amicable pair: %d %d\n", i, amicablePair);
		}
	}

	return 0;
}
