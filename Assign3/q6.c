#include <stdio.h>

int main()
{
	printf("Enter 2 numbers and choice (0: sum, 1: difference, 2: product, 3: quotent): ");
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	switch(c)
	{
		case 0: printf("Sum: %d\n", a + b); break;
		case 1: printf("Difference: %d\n", a - b); break;
		case 2: printf("Product: %d\n", a * b); break;
		case 3: printf("Quotent: %d\n", a / b); break;
		default: puts("Invalid choice");
	}

	return 0;
}
