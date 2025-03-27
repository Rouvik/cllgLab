#include <stdio.h>

#include "src/buffer.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

buffer_t buf = (buffer_t){NULL, 0, 0};

void handle_term(int sig)
{
	freeBuffer(&buf);
	exit(0);
}

int main()
{

	signal(SIGINT, handle_term);
	buffer_t buf = createBuffer(20, 20);	
	while(1)
	{
		
	}

	freeBuffer(&buf);
	return 0;
}
