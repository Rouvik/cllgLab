#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	puts("Before sleep");
	sleep(1);
	puts("After sleep");
	return 0;
}
