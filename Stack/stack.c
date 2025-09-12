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

int main(int argc, const char *argv[])
{
	bool running = true;
  
  printf("Enter size of stack: ");
  int size;
  scanf("%d", &size);

  Stack_t st = Stack_create(size);

  while (running)
  {
    printf("Input choice:\n1) Push an element\n2) Pop an element\n3) Peek element\n4) Quit\n> ");
    int ch;
    scanf("%d", &ch);

    switch (ch)
    {
      case 1:
      {
        printf("Enter an element to push: ");
        int n;
        scanf("%d", &n);
        Stack_push(&st, n);

        Stack_print(&st);
        putchar('\n');
      }
      break;
      
      case 2:
      {
        int t = Stack_pop(&st);
        printf("Popped: %d\n", t);

        Stack_print(&st);
        putchar('\n');
      }
      break;

      case 3:
      {
        int t = Stack_peep(&st);
        printf("Element peeked: %d\n", t);

        Stack_print(&st);
        putchar('\n');
      }
      break;

      case 4:
        running = false;
      break;

      default:
        printf("Unknown case\n");
    }
  }

  Stack_free(&st);
	return 0;
}
