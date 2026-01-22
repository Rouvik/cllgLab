#include <stdio.h>
#include <limits.h>

#include "LinkedList.h"
#include "stack.h"

int main(int argc, const char *argv[])
{
	Node_t *root = NULL;

	int i = 0;

	printf("Enter numbers until -999:\n");
	for (;; i++)
	{
		int x;
		scanf("%d", &x);

		if(x == -999)
		{
			break;
		}

		Node_insertAfter(&root, x, INT_MAX);
	}
	
	// main algo begins here this is O(n) time complexity and O(n) space complexity

	Stack_t st = Stack_create(i);
	Node_t *ptr = root;
	while (ptr)
	{
		Stack_push(&st, ptr->data);
		ptr = ptr->next;
	}

	ptr = root;
	int flag = 0;
	while (ptr)
	{
		if (ptr->data != Stack_pop(&st))
		{
			printf("Not palindrome!\n");
			flag = 1;
			break;
		}
		
		ptr = ptr->next;
	}
	
	if (!flag)
	{
		printf("Palindrome\n");
	}
	
	Node_free(root);
	Stack_free(&st);

	return 0;
}
