#include <stdio.h>

int main()
{
	printf("Enter a number: ");
	int n;
	scanf("%d", &n);

	int t = n, invert = 0;
	while(t > 0)
	{
		invert = invert * 10 + (t % 10);
		t /= 10;
	}

	if(n == invert)
	{
		printf("%d is palindrome\n", n);
	}
	else
	{
		printf("%d is NOT palindrome\n", n);
	}

	return 0;
}
