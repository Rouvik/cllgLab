#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct HashTable
{
	int *container;
	int length;
} HashTable_t;

HashTable_t HashTable_init(int length)
{
	int *arr = (int *)malloc(length * sizeof(int));
	// fill container with default error value INT_MIN
	for(int i = 0; i < length; i++)
	{
		arr[i] = INT_MIN;
	}

	return (HashTable_t){ .container = arr, .length = length };
}

void HashTable_print(HashTable_t *ht)
{
	for(int i = 0; i < ht->length; i++)
	{
		printf("%d ", ht->container[i]);
	}
}

void HashTable_free(HashTable_t *ht)
{
	free(ht->container);
	ht->length = 0;
}

int HashTable_hash(HashTable_t *ht, int data)
{
	printf("DBG :: Data: %d Key: %d\n", data, data % ht->length);
	return data % ht->length;
}

void HashTable_insert(HashTable_t *ht, int data)
{
	int key = HashTable_hash(ht, data);
	int i = 0;
	while(i <= ht->length)	// run upto the entire array and try to insert
	{
		if(ht->container[key] == INT_MIN)
		{
			ht->container[key] = data;
			return;
		}
		else
		{
			key = (key + 1) % ht->length;
		}
		i++;
	}

	printf("Error failed to insert %d to hash table, no available location found\n", data);
}

int main(int argc, const char *argv[])
{
	HashTable_t ht = HashTable_init(5);

	printf("Enter 5 numbers: ");
	int x;
	for(int i = 0; i < 5; i++)
	{
		scanf("%d", &x);
		HashTable_insert(&ht, x);
	}

	printf("Contents of hash table: ");
	HashTable_print(&ht);
	putchar('\n');

	HashTable_free(&ht);
	return 0;
}
