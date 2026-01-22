#ifndef INCLUDED_QUEUE
#define INCLUDED_QUEUE

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Stack
{
  int *arr;
  int capacity;
  int top;
} Stack_t;

Stack_t Stack_create(int capacity)
{
  Stack_t st;
  st.arr = (int *)malloc(capacity * sizeof(int));
  st.capacity = capacity;
  st.top = -1;

  return st;
}

void Stack_free(Stack_t *st)
{
  if (st != NULL)
  {
    free(st->arr);
    st->capacity = 0;
    st->top = -1;
    st->arr = NULL;
  }
}

void Stack_push(Stack_t *st, int data)
{
  if (st->top == st->capacity - 1)
  {
    printf("Error overflow\n");
    return;
  }

  st->arr[++st->top] = data;
}

int Stack_pop(Stack_t *st)
{
  if (st->top == -1)
  {
    printf("Error underflow\n");
    return -999;
  }

  return st->arr[st->top--];
}

int Stack_peep(Stack_t *st)
{
  if (st->top == -1)
  {
    printf("Error underflow\n");
    return -999;
  }

  return st->arr[st->top];
}

void Stack_print(Stack_t *st)
{
  if (st->top == -1)
  {
    printf("[]");
    return;
  }

  printf("[ ");
  for (int i = 0; i <= st->top; i++)
  {
    printf("%d ", st->arr[i]);
  }
  printf("]");
}

#endif  // INCLUDED_QUEUE