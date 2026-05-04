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
	BENCH(10, 10000, n *= 10)
	{
		int volatile out;
		MEASURE_T(20)
		{
			out = fact(n);
		}

		BENCH_STACK_RST();
		BENCH_HEAP_RST();
		out = factm(n);

		if (IS_HEAP_LEAKY)
		{
			fputs("Error heap is leaky\n", stderr);
		}

		PRINT_MEASURE();
	}

	return 0;
}
