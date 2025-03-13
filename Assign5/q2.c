#include <stdio.h>

int main()
{
	printf("Enter a number: ");
	int n;
	scanf("%d", &n);

	int a = 1, b = 1, c = 0, prev = 4;
	for(int i = 0; i < n; i++)
	{
		c = a + b;
		a = b;
		b = c;

		
		for(int j = prev; j < c; j++)
		{
			printf("%d ", j);
		}
		
		prev = c + 1;
	}

	return 0;
}
