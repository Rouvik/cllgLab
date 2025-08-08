#include <stdio.h>

int main()
{
	int i = 123456;
	printf("Formatted output: %.10d, %d\n", i, i);
	printf("Formatted output: %10d, %d\n", i, i);
	return 0;
}
