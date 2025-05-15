#include <stdio.h>

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	printf("Enter 2 numbers: ");
	int a, b;
	scanf("%d %d", &a, &b);

	printf("a = %d b = %d\n", a, b);

	swap(&a, &b);

	printf("a = %d b = %d\n", a, b);
	return 0;
}
