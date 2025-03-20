#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

int main()
{
	//struct timespec slptime = {1, 0};
	for(int i = 1; i <= 20; i++)
	{
		system("clear");
		putchar('[');
		for(int j = 0; j <= i; j++)
		{
			putchar('#');
		}
		printf("%20s", "]");
		//nanosleep(&slptime, NULL);
	}

	return 0;
}
