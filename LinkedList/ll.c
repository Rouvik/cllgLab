#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node_t;

Node_t *Node_init(int value)
{
	Node_t *node = (Node_t *)malloc(sizeof(Node_t));
	node->data = value;
	node->next = NULL;
	return node;
}

void Node_free(Node_t *root)
{
	Node_t *ptr = root;
	while(ptr)
	{
		Node_t *temp = ptr;
		ptr = ptr->next;
		free(temp);
	}
}

void Node_insertFirst(Node_t **root, int value)
{
	if(!*root)
	{
		*root = Node_init(value);
		return;
	}

	Node_t *node = Node_init(value);
	node->next = *root;
	*root = node;
}

void Node_insertLast(Node_t **root, int value)
{
	if(!*root)
	{
		*root = Node_init(value);
		return;
	}

	Node_t *ptr = *root;
	while(ptr->next)
	{
		ptr = ptr->next;
	}

	ptr->next = Node_init(value);
}

void Node_insertAfter(Node_t **root, int value, int index)
{
	if(!*root)
	{
		*root = Node_init(value);
		return;
	}

	Node_t *ptr = *root;
	while(ptr->next != NULL && index != 0)
	{
		ptr = ptr->next;
	}

	Node_t *temp = Node_init(value);
	temp->next = ptr->next;
	ptr->next = temp;
}

void Node_print(Node_t *root)
{
	Node_t *ptr = root;
	printf("[ ");
	while(ptr)
	{
		printf("%d, ", ptr->data);
		ptr = ptr->next;
	}

	printf("]\n");
}

int main()
{
	Node_t *root = NULL;

	int running = 1;
	while(running)
	{
		printf("1) Insert Last\n2) Insert first\n3) Insert Any\n4) Print\n5) Quit\n> ");
		int ch;
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
			{
				printf("Enter element to insert: ");
				int x;
				scanf("%d", &x);
				Node_insertFirst(&root, x);
				printf("Output: ");
				Node_print(root);
			}
			break;

			case 2:
			{
				printf("Enter element to insert: ");
				int x;
				scanf("%d", &x);
				Node_insertLast(&root, x);
				printf("Output: ");
				Node_print(root);
			}
			break;

			case 3:
			{
				printf("Enter element to insert and its index: ");
				int x, i;
				scanf("%d %d", &x, &i);
				Node_insertAfter(&root, x, i);
				printf("Output: ");
				Node_print(root);
			}
			break;

			case 4:
			{
				printf("Output: ");
				Node_print(root);
			}
			break;

			case 5:
			running = 0;
			break;

			default:
			printf("Unknown operation...\n");
		}
	}

	Node_free(root);

	return 0;
}
