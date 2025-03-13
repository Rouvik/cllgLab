#include <stdio.h>

int main()
{
	int year;
	puts("Enter the year:");
	scanf("%d", &year);
	char divBy4 = year % 4 == 0;
	if(divBy4 && year % 100 != 0)
	{
		puts("Leap year!");
	}
	else if(divBy4 && year % 100 == 0 && year % 400 == 0)
	{
		puts("Leap year!");
	}
	else
	{
		puts("Not a Leap year");
	}
	return 0;
}

