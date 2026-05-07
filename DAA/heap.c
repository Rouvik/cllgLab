#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>

void genRandArr(int *arr, int n, int range)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % range;
	}
}

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

#define Heap_pindex(n) (n / 2)
#define Heap_lcindex(n) (2 * n)
#define Heap_rcindex(n) (2 * n + 1)

Heap_t Heap_init(int n)
{
	return (Heap_t){
		.arr = (int *)malloc(n * sizeof(int)),
		.n = n,
		.i = 0};
}

void Heap_free(Heap_t *hp)
{
	free(hp->arr);
}

void Heap_trickleUp(Heap_t *hp, int i)
{
	if (i == 0)
		return;

	int pi = Heap_pindex(i);
	if (hp->arr[pi] < hp->arr[i])
	{
		swap(&(hp->arr[pi]), &(hp->arr[i]));
		Heap_trickleUp(hp, pi);
	}
}

void Heap_insert(Heap_t *hp, int data)
{
	hp->arr[(hp->i)++] = data;
	Heap_trickleUp(hp, hp->i - 1);
}

void Heap_trickleDown(Heap_t *hp, int i)
{
	int lci = Heap_lcindex(i);

	if (lci >= hp->i)
		return;

	int rci = Heap_rcindex(i);

	int larger_index = rci >= hp->i ? lci : (hp->arr[lci] >= hp->arr[rci] ? lci : rci);

	if (hp->arr[i] < hp->arr[larger_index])
	{
		swap(&(hp->arr[i]), &(hp->arr[larger_index]));
		Heap_trickleDown(hp, larger_index);
	}
}

int Heap_remove(Heap_t *hp)
{
	int x = hp->arr[0];
	hp->arr[0] = hp->arr[--(hp->i)];
	Heap_trickleDown(hp, 0);

	return x;
}

int main()
{
	int max_n;
	printf("Enter max n: ");
	scanf("%d", &max_n);

	int randoms[max_n];
	genRandArr(randoms, max_n, 100);

	printf("n\ttime\t\tspace\n");
	for (int n = 10; n <= max_n; n *= 10)
	{
		Heap_t hp = Heap_init(n);

		clock_t st = clock();
		for (int i = 0; i < n; i++)
		{
			Heap_insert(&hp, randoms[i]);
		}

		for (int i = n - 1; i >= 0; i--)
		{
			hp.arr[i] = Heap_remove(&hp);
		}
		clock_t end = clock();
		Heap_free(&hp);

		struct rusage usage;
		getrusage(RUSAGE_SELF, &usage);

		printf("%d\t%lf\t%ld\n", n, (double)(end - st) / CLOCKS_PER_SEC, usage.ru_maxrss);
	}

	return 0;
}
