#include <stdio.h>

int main()
{
	printf("Enter a number: ");
	int n;
	scanf("%d", &n);

	int a = 3, b = 5, c = 5;
	for(int i = 4, j = 0; j < n; i++, j++)
	{
		if(i == c)
		{
			c = a + b;
			a = b;
			b = c;
			j--; // ignore the fibonacci number itself
			continue;
		}
		printf("%d ", i);
	}

	return 0;
}
