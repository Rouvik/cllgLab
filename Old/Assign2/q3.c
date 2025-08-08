#include <stdio.h>

int main()
{
	int x = 130124;
	printf("Original number: %d\nUnit\'s place: %d\nTen\'s place: %d\n", x, x % 10, (x / 10) % 10);
	return 0;
}
