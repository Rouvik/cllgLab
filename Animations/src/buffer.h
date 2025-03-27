#ifndef BUFFER_H
#define BUFFER_H

#include "util.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct buffer
{
	char *buf;
	int width;
	int height;
} buffer_t; 

buffer_t createBuffer(int w, int h);
void freeBuffer(buffer_t *buf);

void fillRect(buffer_t *buffer, int x, int y, int w, int h, char ch);

#endif // BUFFER_H

