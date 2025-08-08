#include <stdio.h>

int main()
{
	int a, b;
	puts("Enter 2 numbers: ");
	scanf("%d %d", &a, &b);

	printf("Sum: %d\nDiffference: %d\nProduct: %d\nQuotent: %lf\nRemainder: %d\n",
		a + b, a - b, a * b, (double)a / b, a % b);
	return 0;
}
