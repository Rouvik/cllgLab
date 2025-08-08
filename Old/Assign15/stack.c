#include <stdio.h>

typedef struct Stack {
	int capacity;
	int *arr;
} Stack_t;

Stack_t Stack_init(int capacity)
{
	Stack_t s;
	s.capacity = capacity;
	s.arr = calloc(capacity, sizeof(int));
	return s;
}

int main()
{
	
}
