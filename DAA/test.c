#include <stdio.h>

#define RTBENCH_IMPLEMENTATION
#include "rtbench.h"

int fact(int n)
{
	return n == 1 ? 1 : n * fact(n - 1);
}

int factm(int n)
{
	BENCH_STACK_MSR();
	return n == 1 ? 1 : n * factm(n - 1);
}

int main()
{
	FILE *fp = fopen("./bench.csv", "w");

	BENCH(10, 10000, n += 50)
	{
		int volatile out;
		MEASURE_T()
		{
			out = fact(n);
		}

		BENCH_STACK_PROBE();
		out = factm(n);

		// PRINT_MEASURE();
		fprintf(fp, "%d,%f,%ld\n", n, (double)(measure_end_ - measure_st_) / CLOCKS_PER_SEC, BENCH_STACK_HIGH - BENCH_STACK_LOW);
	}

	fclose(fp);

	return 0;
}
