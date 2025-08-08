#include <stdio.h>

typedef char bool;

#define true 1
#define false 0

double mysqrt(int n)
{
	double x = n;
	while(x * x - n > 0.0001)
	{
		x = (x * x + n) / (2 * x);
	}
	return x;
}

bool isPrime(int n)
{
	if(n <= 1 || n == 4)
	{
		return false;
	}
	else if(n == 2 || n == 3)
	{
		return true;
	}

	for(int i = 2; i < mysqrt(n); i++)
	{
		if(n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	puts("Input limit to test: ");
	int n;
	scanf("%d", &n);
	for(int i = 2; i < n; i++)
	{
		if(isPrime(i))
		{
			printf("%d\n", i);
		}
	}

	return 0;
}
