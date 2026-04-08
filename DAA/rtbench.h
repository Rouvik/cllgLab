#ifndef RTBENCH_INCLUDE
#define RTBENCH_INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

#ifdef BENCH_OUT_TO_FILE
#define BENCH(fname, start_size, end_size, incr)                                                         \
	for (FILE *fp = fopen(fname, "w"); fp && (fputs("index\tn\tticks\n", fp), 1); fclose(fp), fp = NULL) \
		for (int i = 1, n = start_size; n <= end_size; incr, i++)

#define MEASURE_T(...)                                                     \
	clock_t measure_st_##__VA_ARGS__ = clock(), measure_end_##__VA_ARGS__; \
	for (int _once = 1; _once; measure_end_##__VA_ARGS__ = clock(), _once = 0)

#define PRINT_MEASURE(...) \
	fprintf(fp, "%d\t%d\t%ld\n", i, n, measure_end_##__VA_ARGS__ - measure_st_##__VA_ARGS__);

#else
#define BENCH(start_size, end_size, incr) \
	printf("index\tn\tticks\n");          \
	for (int i = 1, n = start_size; n <= end_size; incr, i++)

#define MEASURE_T(...)                                                     \
	clock_t measure_st_##__VA_ARGS__ = clock(), measure_end_##__VA_ARGS__; \
	for (int _once = 1; _once; measure_end_##__VA_ARGS__ = clock(), _once = 0)

#define PRINT_MEASURE(...) \
	printf("%d\t%d\t%ld\n", i, n, measure_end_##__VA_ARGS__ - measure_st_##__VA_ARGS__);
#endif

#endif // RTBENCH_INCLUDE
