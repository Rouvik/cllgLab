#ifndef INCLUDED_LINKED_LIST
#define INCLUDED_LINKED_LIST

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

Node_t* Node_insertFirst(Node_t **root, int value)
{
	if(!*root)
	{
		*root = Node_init(value);
		return *root;
	}

	Node_t *node = Node_init(value);
	node->next = *root;
	*root = node;

	return node;
}

Node_t * Node_insertLast(Node_t **root, int value)
{
	if(!*root)
	{
		*root = Node_init(value);
		return *root;
	}

	Node_t *ptr = *root;
	while(ptr->next)
	{
		ptr = ptr->next;
	}

	ptr->next = Node_init(value);
	return ptr->next;
}

Node_t * Node_insertAfter(Node_t **root, int value, int index)
{
	if(!*root)
	{
		*root = Node_init(value);
		return *root;
	}

	Node_t *ptr = *root;
	while(ptr->next != NULL && index-- != 0)
	{
		ptr = ptr->next;
	}

	Node_t *temp = Node_init(value);
	temp->next = ptr->next;
	ptr->next = temp;

	return temp;
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

#endif  // INCLUDED_LINKED_LIST