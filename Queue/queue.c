#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
	if(q->back == q->front - 1 || (q->back == q->capacity - 1 && q->front == 0))
	{
		printf("Overflow\n");
		return;
	}
	else if(q->front == -1)
	{
		q->front = 0;
	}

	q->arr[(++q->back) % q->capacity] = data;
}

int Queue_deque(Queue_t *q)
{
	if(q->front == -1 || q->front == q->back + 1)
	{
		printf("Underflow");
		return -999;
	}

	int x = q->arr[q->front];
	q->front = (q->front + 1) % q->capacity;

	if(q->front == q->back)
	{
		q->front = q->back = -1;
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

int main(int argc, const char *argv[])
{
	bool running = true;
	Queue_t q = Queue_create(10);
	while(running)
	{
		printf("Enter choice:b\n1) Enque\n2) Deque\n3) Peep\n4) Quit\n> ");
		int ch;
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
			{
				printf("Enter an element to enque: ");
				int n;
				scanf("%d", &n);

				Queue_enque(&q, n);

				Queue_print(&q);
				putchar('\n');
			}
			break;

			case 2:
			{
				int t = Queue_deque(&q);
				printf("Element deque: %d\n", t);

				Queue_print(&q);
				putchar('\n');
			}
			break;

			case 3:
			{
				int t = Queue_peep(&q);

				printf("Peeped element: %d\n", t);


				Queue_print(&q);
				putchar('\n');
			}
			break;


			case 4:
				running = false;
				break;

			default:
				printf("Unknown case");
		}
	}

	Queue_free(&q);
	return 0;
}

