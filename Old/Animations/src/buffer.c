#include "buffer.h"
buffer_t createBuffer(int w, int h)
{
	buffer_t buf;
	buf.buf = (char *)malloc((w + 1) * h * sizeof(char));
	buf.width = w;
	buf.actualWidth = w + 1;
	buf.height = h;

	cleanBuffer(&buf);

	return buf;
}

void freeBuffer(buffer_t *buf)
{
	free(buf->buf);
	buf->buf = NULL;
	buf->width = 0;
	buf->height = 0;
}

void fillRect(buffer_t *buffer, int x1, int y1, int x2, int y2, char ch)
{
	for(int i = y1; i < y2; i++)
	{
		for(int j = x1; j < x2; j++)
		{
			buffer->buf[i * buffer->width + j] = ch;
		}
	}
}

void blitToScreen(buffer_t *buf)
{
	system("clear");
	fputs(buf->buf, stdout);
	fflush(stdout);
	usleep(BUF_SLEEP_TIME * 1000);
}

void cleanBuffer(buffer_t *buf)
{
	memset(buf->buf, ' ', buf->actualWidth * buf->height);

	for(int i = 0; i < buf->height; i++)
	{
		buf->buf[i * buf->width] = '\n';
	}
}
