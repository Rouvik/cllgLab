#include <stdio.h>

int main()
{
	int a, b;
	puts("Enter 2 numbers:");
	scanf("%d %d", &a, &b);

	if(a > b)
	{
		puts("a greater than b");
	}
	else if(a < b)
	{
		puts("a less than b");
	}
	else
	{
		puts("a equal to b");
	}
	return 0;
}
