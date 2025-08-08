#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main()
{
	printf("Enter a number: ");
	int n;
	scanf("%d", &n);

	bool notPrime = false;
	for(int i = 2; i < sqrt(n); i++)
	{
		if(n % i == 0)
		{
			notPrime = true;
			break;
		}
	}

	if(notPrime)
	{
		printf("%d is not prime\n", n);
	}
	else
	{
		printf("%d is prime\n", n);
	}
	return 0;
}

