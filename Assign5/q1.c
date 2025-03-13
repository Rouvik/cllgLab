#include <stdio.h>

int main()
{
	printf("Enter height: ");
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			printf("%d", j);
		}
		putc('\n', stdout);
	}

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= 2 * i - 1; j++)
		{
			putc('*', stdout);
		}
		putc('\n', stdout);
	}

	int l = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			printf("%d", l++);
		}
		putc('\n', stdout);
	}
	return 0;
}
