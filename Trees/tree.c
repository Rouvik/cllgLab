#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
} Node_t;

Node_t* Node_create(int data)
{
	Node_t* node = (Node_t *)malloc(sizeof(Node_t));

	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void Tree_insert(Node_t **root, int data)
{
	if (!(*root))
	{
		*root = Node_create(data);
		return;
	}
	
	if (data < (*root)->data)
	{
		Tree_insert(&((*root)->left), data);
	}
	else
	{
		Tree_insert(&((*root)->right), data);
	}
}

void Tree_preorder_print(Node_t *root)
{
	if(!root) return;

	printf("%d ", root->data);
	Tree_preorder_print(root->left);
	Tree_preorder_print(root->right);
}

void Tree_inorder_print(Node_t *root)
{
	if(!root) return;

	Tree_inorder_print(root->left);
	printf("%d ", root->data);
	Tree_inorder_print(root->right);
}

void Tree_postorder_print(Node_t *root)
{
	if(!root) return;

	Tree_postorder_print(root->left);
	Tree_postorder_print(root->right);
	printf("%d ", root->data);
}

void Tree_free(Node_t *root)
{
	if(!root) return;

	Tree_free(root->left);
	Tree_free(root->right);
	free(root);
}

int main(int argc, const char *argv[])
{
	Node_t* root = NULL;

	printf("Enter 10 elements:\n");
	for (int i = 0; i < 10; i++)
	{
		int x;
		scanf("%d", &x);
		Tree_insert(&root, x);
	}

	printf("Preorder: ");
	Tree_preorder_print(root);
	putchar('\n');

	printf("Inorder: ");
	Tree_inorder_print(root);
	putchar('\n');
	
	printf("Postorder: ");
	Tree_postorder_print(root);
	putchar('\n');

	Tree_free(root);

	return 0;
}
