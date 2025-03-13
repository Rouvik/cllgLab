#include <stdio.h>

int main()
{
	int i = 7, j = 8, k = 5;
	printf("i = %d and j = %d\n", i, j);
	i += k; j -= k;
	printf("i = %d and j = %d\n", i, j);
	i++; --j;
	printf("i = %d and j = %d\n", i, j);
	int a = i++; int b = --j;
	printf("i = %d and a = %d\n", i, a);
	printf("j = %d and b = %d\n", j, b);
	return 0;
}
