#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int main()
{
	time_t tm;
	struct tm *lcltime;
	while (1)
	{
		time(&tm);
		lcltime = localtime(&tm);
		char *str = asctime(lcltime);
		str[strlen(str) - 1] = '\0';
		printf("\r%s", str);
		fflush(stdout);
		sleep(1);
	}
	return 0;
}
