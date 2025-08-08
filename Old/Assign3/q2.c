#include <stdio.h>

int main()
{
	puts("Enter 3 numbers:");
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	
	if(a > b)
	{
		if(a > c)
		{
			printf("Largest: %d\n", a);
		}
		else
		{
			printf("Largest: %d\n", c);
		}
	}
	else if(b > c)
	{
		printf("Largest: %d\n", b);
	}
	else
	{
		printf("Largest: %d\n", c);
	}
	return 0;
}
