#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

typedef struct Heap
{
	int *arr;
	int n;
	int i;
} Heap_t;

#define Heap_pindex(n) ((int)floor(n / 2))
#define Heap_lcindex(n) (2 * n)
#define Heap_rcindex(n) (2 * n + 1)

Heap_t Heap_init(int n)
{
	Heap_t hp = {
		.arr = (int *)malloc(n * sizeof(int)),
		.n = n,
		.i = 0
	};

	return hp;
}

void Heap_free(Heap_t *hp)
{
	free(hp->arr);
}

void Heap_insert(Heap_t *hp, int data)
{
	hp->arr[(hp->i)++] = data;
	Heap_trickleUp(hp, hp->i);
}

void Heap_trickleUp(Heap_t *hp, int i)
{
	if(i == 0) return;

	int pi = Heap_pindex(i);
	if(hp->arr[pi] > hp->arr[i])
	{
		swap(&(hp->arr[pi]), &(hp->arr[i]));
		Heap_trickleUp(hp, pi);
	}
}

int main(int argc, const char *argv[])
{
	
	return 0;
}
