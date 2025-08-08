#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SEARCH_ERROR -1

typedef struct Array
{
	int *arr;
	int capacity;
	int size;
} Array_t;

Array_t initArray(int capacity)
{
	Array_t array;
	array.arr = (int *) calloc(capacity, sizeof(int));
	array.size = 0;
	array.capacity = capacity;

	return array;
}

void insertAt(Array_t *array, int index, int element)
{
	if(array->size >= array->capacity || index > array->size)
	{
		puts("Error overflow");
		return;
	}
	else if(index >= array->capacity)
	{
		puts("Illegal position out of bounds");
		return;
	}

	if(index >= array->size)
	{
		array->arr[index] = element;
	}
	else
	{
		for(int i = array->size; i > index; i--)
		{
			array->arr[i] = array->arr[i - 1];
		}
		array->arr[index] = element;
	}

	array->size++;
}

int search(Array_t *array, int element)
{
	for(int i = 0; i < array->size; i++)
	{
		if(array->arr[i] == element) return i;
	}

	return SEARCH_ERROR;
}

void freeArray(Array_t *array)
{
	free(array->arr);
	array->arr = NULL;
	array->capacity = 0;
	array->size = 0;
}

void printArr(Array_t *array)
{
	for(int *i = array->arr; i < array->arr + array->capacity; i++)
	{
		printf("%d ", *i);
	}
	putchar('\n');
}

int main()
{
	int capacity;
	fputs("Enter size of array: ", stdout);
	scanf("%d", &capacity);

	Array_t array = initArray(capacity);

	bool running = true;
	while(running)
	{
		char ch;
		int x, i;
		fputs("Enter choice:\n1)Insert at end\n2)Insert at start\n3)Search\n4)Insert at any position\n5)Print\nq)Quit\n> ", stdout);
		while(getchar() != '\n');
		scanf("%c", &ch);

		if(ch == 'q') break;

		ch = ch - '0';

		switch(ch)
		{
			case 1:
				puts("Enter a number to insert:");
				scanf("%d", &x);
				insertAt(&array, array.size, x);
			break;

			case 2:
				puts("Enter a number to insert:");
				scanf("%d", &x);
				insertAt(&array, 0, x);
			break;


			case 3:
				puts("Enter an element to search:");
				scanf("%d", &x);
				i = search(&array, x);
				printf("Element %d index: %d\n", i);
			break;

			case 4:
				puts("Enter an element and an index:");
				scanf("%d %d", &x, &i);
				insertAt(&array, i, x);
			break;

			case 5:
				puts("Array contents:");
				printArr(&array);
			break;

			default:
				puts("Unknown command use q to exit!");
		}
	}
	freeArray(&array);
	return 0;
}
