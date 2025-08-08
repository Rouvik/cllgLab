#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	for(int i = 1; i <= 20; i++)
	{
		system("clear");
		putchar('[');
		for(int j = 1; j <= i; j++)
		{
			putchar('#');
		}
		printf("%*s", 20 - i, "]");
		fflush(stdout); // make sure stuff is printed
		sleep(1);
	}
	return 0;
}
