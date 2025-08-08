#include <stdio.h>

int main()
{
	puts("Enter your name: ");
	char name[16];
	scanf("%16s", name);
	printf("Name            |\n%16s\n", name);
	return 0;
}
