#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
	int data;
	struct Node *prev;
	struct Node *next;
} Node_t;

// Creates a node with data as contained data and prev and next set to NULL
Node_t* Node_create(int data)
{
	Node_t *node = (Node_t *)malloc(sizeof(Node_t));
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return node;
}

// Free the entire Linked List from root and also set root as null
// SIG: Node_free(&root)
void Node_free(Node_t **root)
{
	if(!(*root)) return;

	Node_t *p = *root;
	while(p->next != NULL)
	{
		Node_t* x = p;
		p = p->next;
		free(x);
	}

	*root = NULL;
}

// Returns the length of the Linked List Duh -_-
int Node_length(Node_t *root)
{
	int length = 0;
	while(root->next != NULL)
	{
		root = root->next;
		length++;
	}

	return length;
}

// Insert an element at the explicit index in the linked list
// SIG: Node_insert(&root, data, index)
// Root = 0, if index > List size, insert at last
void Node_insert(Node_t **root, int data, int index)
{
	Node_t *new = Node_create(data);

	// deal with root index
	if(index == 0)
	{
		if(*root)
		{
			new->next = *root;
			(*root)->prev = new;
		}
		*root = new;

		return;
	}

	Node_t *p = *root;
	while(p->next != NULL && index-- > 0)
	{
		p = p->next;
	}

	// index exceeded need to insert last
	if(index > 0)
	{
		p->next = new;
		new->prev = p;

		return;
	}

	p->prev->next = new;
	new->prev = p->prev;
	new->next = p;
	p->prev = new;
}

// wrapper call to Node_insert(root, data, 0)
void Node_insertFirst(Node_t **root, int data)
{
	Node_insert(root, data, 0);
}

// wrapper call to Node_insert(root, data, INT_MAX)
void Node_insertLast(Node_t **root, int data)
{
	Node_insert(root, data, INT_MAX);
}

// Delete an element at the explicit index in the linked list
// SIG: Node_delete(&root, index)
// Root = 0, if index > List size, delete last
int Node_delete(Node_t **root, int index)
{
	if(index == 0)
	{
		Node_t *del = *root;
		int x = del->data;
		*root = (*root)->next;
		free(del);
		return x;
	}

	Node_t *p = *root;
	while(p->next != NULL && index-- > 0)
	{
		p = p->next;
	}

	// index exceeded need to insert last
	if(index > 0)
	{
		int x = p->data;
		Node_t *del = p;
		p->prev->next = NULL;
		free(del);

		return x;
	}

	Node_t *del = p;
	p->prev->next = p->next;
	p->next->prev = p->prev;

	int x = del->data;
	free(del);
	return x;
}

// wrapper call to Node_delete(root, 0)
void Node_deleteFirst(Node_t **root)
{
	Node_delete(root, 0);
}

// wrapper call to Node_delete(root, INT_MAX)
void Node_deleteLast(Node_t **root)
{
	Node_delete(root, INT_MAX);
}

// print the contents of the list
void Node_print(Node_t *root)
{
	fputs("[ ", stdout);
	while(root)
	{
		printf("%d ", root->data);
		root = root->next;
	}

	puts("]");	// note the puts here is used to make sure an extra \n is added as per the C std
}

int main(int argc, const char *argv[])
{
	Node_t *root = NULL;
	int running = 1;
	while(running)
	{
		fputs(	"Enter choice:\n"
			"1)Insert first\n"
			"2)Insert Last\n"
			"3)Insert Any\n"
			"4)Delete First\n"
			"5)Delete Last\n"
			"6)Delete Any\n"
			"7)Print\n"
			"8)Exit\n"
			">", stdout);
		int ch;
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
			{
				fputs("Enter element to insert: ", stdout);
				int n;
				scanf("%d", &n);

				Node_insertFirst(&root, n);
				Node_print(root);
			}
			break;

			case 2:
			{
				fputs("Enter element to insert: ", stdout);
				int n;
				scanf("%d", &n);

				Node_insertLast(&root, n);
				Node_print(root);
			}
			break;

			case 3:
			{
				fputs("Enter element to insert: ", stdout);
				int n;
				scanf("%d", &n);

				fputs("Enter index to insert: ", stdout);
				int i;
				scanf("%d", &i);

				Node_insert(&root, n, i);
				Node_print(root);
			}
			break;

			case 4:
			{
				Node_deleteFirst(&root);
				Node_print(root);
			}
			break;

			case 5:
			{
				Node_deleteLast(&root);
				Node_print(root);
			}
			break;

			case 6:
			{
				fputs("Enter index to delete: ", stdout);
				int i;
				scanf("%d", &i);

				Node_delete(&root, i);
				Node_print(root);
			}
			break;

			case 7:
			{
				fputs("Output: ", stdout);
				Node_print(root);
			}
			break;

			case 8:
				running = 0;
		}
	}

	Node_free(&root);
	return 0;
}
