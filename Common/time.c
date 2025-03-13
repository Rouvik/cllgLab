#include <stdio.h>
#include <time.h>
 
int main()
{
	time_t tm;
	struct tm *lcltime;
	while(1)
	{
		time(&tm);
		lcltime = localtime(&tm);
		printf("\f\r%s          ", asctime(lcltime));
	}
	return 0;
}
