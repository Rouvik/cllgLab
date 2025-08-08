#include <stdio.h>

int main()
{
	printf("Enter rank: "); int rank;
	scanf("%d", &rank);

	if(rank > 100)
	{
		puts("Invalid rank");
		return 0;
	}

	switch(rank / 10)
	{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4: puts("F"); break;
		
		case 5:
		case 6: puts("C"); break;

		case 7:
		case 8: puts("B"); break;

		case 9:
		case 10: puts("A"); break;

		default: puts("Invalid rank");
	}

	return 0;
}


