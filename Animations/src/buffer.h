#ifndef BUFFER_H
#define BUFFER_H

#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUF_SLEEP_TIME 400

typedef struct buffer
{
	char *buf;
	int width;
	int actualWidth;
	int height;
} buffer_t; 

buffer_t createBuffer(int w, int h);
void freeBuffer(buffer_t *buf);

void fillRect(buffer_t *buffer, int x1, int y1, int x2, int y2, char ch);

void blitToScreen(buffer_t *buf);

void cleanBuffer(buffer_t *buf);

#endif // BUFFER_H

