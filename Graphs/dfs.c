#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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

void Graph_dfs(int *adj, int v, int *visited)
{
	// make sure not to start with non existent vertices
	if (v > adj[0])
	{
		printf("Error, vertex greater than maxRadius\n");
		exit(1);
	}

	if(visited[v]) return;	// visited so ignore

	visited[v] = true; // mark as visited, on call
	printf("Visited: %d\n", v);

	for (int i = 0; i < adj[0]; i++)
	{
		if (i == v)
			continue; // dont try to visit self

		if (INDEX_ADJ(adj, v, i)) // go through neighbours and visit
		{
			Graph_dfs(adj, i, visited);
		}
	}
}

int main(int argc, const char *argv[])
{
	int *graph = Graph_init(5);
	Graph_addEdge(graph, 0, 1, false);
	Graph_addEdge(graph, 1, 2, false);
	Graph_addEdge(graph, 2, 0, false);

	Graph_print(graph);
	putchar('\n');

	int visited[5] = {0};

	Graph_dfs(graph, 0, visited);

	Graph_free(&graph);

	return 0;
}
