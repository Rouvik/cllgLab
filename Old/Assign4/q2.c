#include <stdio.h>

int main()
{
	int a = 1, b = 0, c = 0, n;
	printf("Enter the number of terms: ");
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		c = a + b;
		a = b;
		b = c;

		printf("%d ", c);
	}

	putc('\n', stdout);
	return 0;
}
