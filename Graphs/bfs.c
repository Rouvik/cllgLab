#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// my custom queue lib :)
#include <queue.h>

#define INDEX_ADJ(adj, i, j) adj[j * adj[0] + i + 1]

int *Graph_init(int maxRadius)
{
	int *mat = (int *)malloc(maxRadius * maxRadius * sizeof(int) + 1);
	mat[0] = maxRadius;
	return mat;
}

void Graph_free(int **adjMat)
{
	free(*adjMat);
	*adjMat = NULL;
}

void Graph_addEdge(int *adj, int v1, int v2, bool bidirectional)
{
	if (v1 > adj[0] || v2 > adj[0])
	{
		printf("Error, edge greater than accomodable by graph\n");
		return;
	}

	INDEX_ADJ(adj, v1, v2) = 1;

	if (bidirectional)
		INDEX_ADJ(adj, v2, v1) = 1;
}

void Graph_print(int *adj)
{
	fputs("   ", stdout);
	for (int i = 0; i < adj[0]; i++)
	{
		printf("%d ", i);
	}

	putchar('\n');

	fputs("   ", stdout);
	for (int i = 0; i < adj[0]; i++)
	{
		fputs("--", stdout);
	}

	putchar('\n');

	for (int i = 0; i < adj[0]; i++)
	{
		printf("%d| %d ", i, INDEX_ADJ(adj, i, 0));
		for (int j = 1; j < adj[0]; j++)
		{
			printf("%d ", INDEX_ADJ(adj, i, j));
		}
		putchar('\n');
	}
}

void Graph_bfs(int *adj, int v)
{
	int visited[adj[0]];
	memset(visited, 0, sizeof(int) * adj[0]);	// initialise visited with 0

	Queue_t q = Queue_create(adj[0]);

	// insert first node to start visiting
	Queue_enque(&q, v);

	while(true)
	{
		int node = Queue_deque(&q);
		if(node == INT_MIN) break;	// queue empty visiting complete!

		if(visited[node]) continue;	// already visited ignore
		visited[node] = true;

		for(int i = 0; i < adj[0]; i++)
		{
			if(INDEX_ADJ(adj, node, i) && !visited[i])
			{
				Queue_enque(&q, i);	// enque neighbours that are visitable
			}
		}

		printf("Visited: %d\n", node);
	}

	Queue_free(&q);
}

int main()
{
	int *graph = Graph_init(5);

	Graph_addEdge(graph, 0, 1, false);
	Graph_addEdge(graph, 0, 2, false);
	Graph_addEdge(graph, 1, 3, false);

	Graph_print(graph);
	putchar('\n');

	Graph_bfs(graph, 0);

	Graph_free(&graph);

	return 0;
}
