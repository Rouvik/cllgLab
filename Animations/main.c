#include <stdio.h>

#include "src/buffer.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

buffer_t buf = (buffer_t){NULL, 0, 0};

void handle_term(int sig)
{
	freeBuffer(&buf);
	puts("Exitting...");
	exit(0);
}

int main()
{

	signal(SIGINT, handle_term);
	buffer_t buf = createBuffer(20, 20);
	int x = 1;
	while(1)
	{
		cleanBuffer(&buf);
		fillRect(&buf, x, 10, 5 + x, 15, '#');
		x++;
		if(x > 13) x = 0;
		blitToScreen(&buf);
	}

	freeBuffer(&buf);
	return 0;
}
