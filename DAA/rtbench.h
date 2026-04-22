#ifndef RTBENCH_INCLUDE
#define RTBENCH_INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArr(int *arr, int length);
void genRandArr(int *arr, int length, int range);

extern size_t BENCH_STACK_LOW, BENCH_STACK_HIGH;

#define BENCH_STACK_PROBE()                                     \
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

#define BENCH_TIME_AVG_COUNT 1

#ifdef BENCH_OUT_TO_FILE
#define BENCH(fname, start_size, end_size, incr)                                                                \
	for (FILE *fp = fopen(fname, "w"); fp && (fputs("index\tn\tticks\tstack\n", fp), 1); fclose(fp), fp = NULL) \
		for (int i = 1, n = start_size; n <= end_size; incr, i++)

#define MEASURE_T(...)                                                     \
	clock_t measure_st_##__VA_ARGS__ = clock(), measure_end_##__VA_ARGS__; \
	for (int _once = 1; _once; measure_end_##__VA_ARGS__ = clock(), _once = 0)

#define PRINT_MEASURE(...) \
	fprintf(fp, "%d\t%d\t%ld\t%ld\n", i, n, measure_end_##__VA_ARGS__ - measure_st_##__VA_ARGS__, BENCH_STACK_HIGH - BENCH_STACK_LOW);

#else
#define BENCH(start_size, end_size, incr) \
	printf("index\tn\tticks\tstack\n");   \
	for (int i = 1, n = start_size; n <= end_size; incr, i++)

#define MEASURE_T(...)                                                     \
	clock_t measure_st_##__VA_ARGS__ = clock(), measure_end_##__VA_ARGS__; \
	for (int _once = 1; _once; measure_end_##__VA_ARGS__ = clock(), _once = 0)

#define PRINT_MEASURE(...) \
	printf("%d\t%d\t%ld\t%ld\n", i, n, measure_end_##__VA_ARGS__ - measure_st_##__VA_ARGS__, BENCH_STACK_HIGH - BENCH_STACK_LOW);
#endif

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

size_t BENCH_STACK_LOW, BENCH_STACK_HIGH;

#endif

#endif // RTBENCH_INCLUDE