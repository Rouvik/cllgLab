#include <stdio.h>

int main(int argc, const char *argv[])
{
	printf("Enter n: ");
	int n;
	scanf("%d", &n);

	int bitsum = 0, t = n;
	while (t > 0)
	{
		bitsum += t & 1;
		t >>= 1;
	}

	bitsum &= 3;	// % 4 for the 15 case

	printf("Closest = %d\n", ((n & ~3) | (bitsum & 3)));

	return 0;
}
