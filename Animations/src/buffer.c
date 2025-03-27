#include "buffer.h"
buffer_t createBuffer(int w, int h)
{
	buffer_t buf;
	buf.buf = (char *)malloc((w + 1) * h * sizeof(char));
	buf.width = w;
	buf.actualWidth = w + 1;
	buf.height = h;

	for(int i = 0; i < h; i++)
	{
		buf.buf[]
	}

	return buf;
}

void freeBuffer(buffer_t *buf)
{
	free(buf->buf);
	buf->buf = NULL;
	buf->width = 0;
	buf->height = 0;
}

void fillRect(buffer_t *buffer, int x, int y, int w, int h, char ch)
{
	for(int i = y; i < h; i++)
	{
		for(int j = x; j < w; j++)
		{
			buffer->buf[i * buffer->width + j] = ch;
		}
	}
}
