#include <stdio.h>

int main()
{
	int a = 3, b = 5;
	puts("Using temporary variable:\n");
	printf("Before swapping: a=%d b=%d\n", a, b);

	// swap with extra variables
	int t = a;
	a = b;
	b = t;
	
	printf("After swapping: a=%d b=%d\n", a, b);

	
	// swap with no extra variables

	a = 3, b = 5;
	puts("\nWithout using temporary variable:\n");
	printf("Before swapping: a=%d b=%d\n", a, b);

	// swap with extra variables
	
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;

	printf("Before swapping: a=%d b=%d\n", a, b);
	return 0;
}
