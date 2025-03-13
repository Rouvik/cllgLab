#include <stdio.h>
#include <stdbool.h>

int main()
{
	printf("Enter a number: ");
	int n;
	scanf("%d", &n);

	for(int i = 2; i <= n; i++)
	{
		bool notPrime = false;
		for(int j = 2; j < sqrt(i); j++)
		{
			if(i % j == 0)
			{
				notPrime = true;
				break;
			}
		}
