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

bool Graph_cycleDetect(int *adj, int p, int v, int *visited)
{
	// make sure not to start with non existent vertices
	if (v > adj[0])
	{
		printf("Error, vertex greater than maxRadius\n");
		return false;
	}

	visited[v] = true; // mark as visited, on call

	for (int i = 0; i < adj[0]; i++)
	{
		if (i == v || i == p)
			continue; // dont try to visit self or consider its previous

		if (INDEX_ADJ(adj, v, i)) // go through neighbours and visit, if visited -> CYCLE :)
		{
			if (visited[i] || Graph_cycleDetect(adj, v, i, visited))
				return true;
		}
	}

	return false;
}

int main(int argc, const char *argv[])
{
	int *graph = Graph_init(5);
	Graph_addEdge(graph, 0, 1, true);
	Graph_addEdge(graph, 1, 2, true);
	Graph_addEdge(graph, 2, 0, true);

	Graph_print(graph);
	putchar('\n');

	int visited[5];

	printf("Has cycles? %s\n", Graph_cycleDetect(graph, -1, 0, visited) ? "TRUE" : "FALSE");

	Graph_free(&graph);

	return 0;
}
