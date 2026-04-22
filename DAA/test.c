#include <stdio.h>

size_t stack_low = 0;
size_t stack_high = 0;

#define mstack_begin() 					\
do { 							\
	asm("mov %%rsp, %0" : "=r" (stack_high)); 	\
	stack_low = stack_high; 			\
} while(0);

#define mstack_probe()				\
do {						\
	size_t x = 0;				\
	asm("mov %%rsp, %0" : "=r" (x));	\
	if(stack_low > x) stack_low = x;	\
} while(0);

int fact(int n)
{
	volatile int x = 100;
	mstack_probe();
	return n == 1 ? 1 : n * fact(n - 1);
}

int main()
{
	mstack_begin();
	int out = fact(5);

	printf("%d\n", out);

	printf("%ld\n", stack_high - stack_low);

	return 0;
}
