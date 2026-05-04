#ifndef RTBENCH_INCLUDE
#define RTBENCH_INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArr(int *arr, int length);
void genRandArr(int *arr, int length, int range);
void *bmalloc(size_t size);
void bfree(void *ptr);

extern size_t BENCH_STACK_LOW, BENCH_STACK_HIGH;
extern size_t BENCH_HEAP_TOTAL, BENCH_HEAP_CURRENT;

#define BENCH_STACK_RST()                                       \
	do                                                          \
	{                                                           \
		asm volatile("mov %%rsp, %0" : "=r"(BENCH_STACK_HIGH)); \
		BENCH_STACK_LOW = BENCH_STACK_HIGH;                     \
	} while (0);

#define BENCH_STACK_MSR()                        \
	do                                           \
	{                                            \
		register size_t x = 0;                   \
		asm volatile("mov %%rsp, %0" : "=r"(x)); \
		if (BENCH_STACK_LOW > x)                 \
			BENCH_STACK_LOW = x;                 \
	} while (0);

#define BENCH_HEAP_RST()        \
	do                          \
	{                           \
		BENCH_HEAP_TOTAL = 0;   \
		BENCH_HEAP_CURRENT = 0; \
	} while (0);

#define IS_HEAP_LEAKY (BENCH_HEAP_CURRENT != 0)

#define MEASURE_T(avg_count, ...)                                                                                                          \
	clock_t measure_time_##__VA_ARGS__ = 0;                                                                                                \
	for (clock_t total = 0, _avg_out_once = 1, _i = 0; _avg_out_once; measure_time_##__VA_ARGS__ = total / (avg_count), _avg_out_once = 0) \
		for (; _i < (avg_count); _i++)                                                                                                     \
			for (clock_t st = clock(), _once = 1; _once; total += clock() - st, _once = 0)

#ifdef BENCH_OUT_TO_FILE
#define BENCH(fname, start_size, end_size, incr)                                                                \
	for (FILE *fp = fopen(fname, "w"); fp && (fputs("index\tn\tticks\tstack\theap\n", fp), 1); fclose(fp), fp = NULL) \
		for (int i = 1, n = start_size; n <= end_size; incr, i++)

#define PRINT_MEASURE(...) \
	fprintf(fp, "%d\t%d\t%ld\t%ld\t%ld\n", i, n, measure_time_##__VA_ARGS__, BENCH_STACK_HIGH - BENCH_STACK_LOW, BENCH_HEAP_TOTAL);

#else
#define BENCH(start_size, end_size, incr) \
	printf("index\tn\tticks\tstack\theap\n");   \
	for (int i = 1, n = start_size; n <= end_size; incr, i++)

#define PRINT_MEASURE(...) \
	printf("%d\t%d\t%ld\t%ld\t%ld\n", i, n, measure_time_##__VA_ARGS__, BENCH_STACK_HIGH - BENCH_STACK_LOW, BENCH_HEAP_TOTAL);
#endif

// -------------------------------- IMPLEMENTATION --------------------------------
#ifdef RTBENCH_IMPLEMENTATION

void printArr(int *arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
}

void genRandArr(int *arr, int length, int range)
{
	srand(time(NULL));
	for (int i = 0; i < length; i++)
	{
		arr[i] = rand() % range;
	}
}

void genRandSortedArr(int *arr, int length, int growth)
{
	srand(time(NULL));

	int s = 0;
	for (int i = 0; i < length; i++)
	{
		s += rand() % growth;
		arr[i] = s;
	}
}

void *bmalloc(size_t size)
{
	size_t *ptr = malloc(size + sizeof(size_t));
	if (!ptr)
	{
		return NULL;
	}

	*ptr = size;
	BENCH_HEAP_TOTAL += size;
	BENCH_HEAP_CURRENT += size;
	return ptr + 1;
}

void bfree(void *ptr)
{
	if (!ptr)
	{
		return;
	}

	size_t *alloc_size = (size_t *)ptr - 1;
	BENCH_HEAP_CURRENT -= *alloc_size;
	free(alloc_size);
}

size_t BENCH_STACK_LOW, BENCH_STACK_HIGH;
size_t BENCH_HEAP_TOTAL, BENCH_HEAP_CURRENT;

#endif

#endif // RTBENCH_INCLUDE