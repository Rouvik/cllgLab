#ifndef INCLUDED_QUEUE
#define INCLUDED_QUEUE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Queue
{
	int *arr;
	int capacity;
	int front;
	int back;
} Queue_t;

Queue_t Queue_create(int capacity)
{
	Queue_t q;
	q.arr = (int *)malloc(sizeof(int) * capacity);
	q.capacity = capacity;
	q.front = -1;
	q.back = -1;

	return q;
}

void Queue_free(Queue_t *q)
{
	if(q != NULL)
	{
		free(q->arr);
		q->capacity = 0;
		q->front = -1;
		q->back = -1;
		q->arr = NULL;
	}
}

void Queue_enque(Queue_t *q, int data)
{
	if((q->front != -1 && q->back == q->front) || (q->back == q->capacity - 1 && q->front == 0))
	{
		printf("Overflow\n");
		return;
	}
	else if(q->front == -1)
	{
		q->front = 0;
		q->back = 0;
	}

	q->arr[q->back] = data;
	q->back = (q->back + 1) % q->capacity;
}

int Queue_deque(Queue_t *q)
{
	if(q->front == -1)
	{
		// printf("Underflow");
		return INT_MIN;
	}

	int x = q->arr[q->front];
	q->front = (q->front + 1) % q->capacity;

	if(q->front == q->back)
	{
		q->front = -1;
		q->back = -1;
	}

	return x;
}

int Queue_peep(Queue_t *q)
{
	return q->arr[q->front];
}

void Queue_print(Queue_t *q)
{
	if(q->front == -1 && q->back == -1)
	{
		printf("[]");
		return;
	};

	printf("[ ");
	for(int i = q->front; i != q->back; i = (i + 1) % q->capacity)
	{
		printf("%d ", q->arr[i]);
	}
	printf("]");
}

#endif	// INCLUDED_QUEUE

