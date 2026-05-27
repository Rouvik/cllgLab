#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define INDEX(g, i, j) (g->graph[i * g->rad + j])

typedef struct Graph
{
	int *graph;
	int rad;
} Graph_t;

Graph_t Graph_init(int rad)
{
	Graph_t g = {
		.graph = calloc(rad * rad, sizeof(int)),
		.rad = rad
	};

	for(int i = 0; i < rad; i++)
	{
		for(int j = 0; j < rad; j++)
		{
			if(i != j) INDEX((&g), i, j) = 999;
		}
	}

	return g;
}

void Graph_free(Graph_t *g)
{
	free(g->graph);
	g->graph = NULL;
	g->rad = 0;
}

void Graph_print(Graph_t *graph)
{
	for(int i = 0; i < graph->rad; i++)
	{
		for(int j = 0; j < graph->rad; j++)
		{
			printf("%d ", INDEX(graph, i, j));
		}
		putchar('\n');
	}
}


void Graph_edgeTo(Graph_t *graph, int a, int b, int weight, int bidirectional)
{
	INDEX(graph, a, b) = weight;

	if(bidirectional)
	{
		INDEX(graph, b, a) = weight;
	}
}

void Graph_floyd(Graph_t *g)
{
	const int rad = g->rad;
	for(int k = 0; k < rad; k++)
	{
		int newG[rad][rad];
		memcpy(newG, g->graph, sizeof(int) * rad * rad);
		for(int i = 0; i < g->rad; i++)
		{
			for(int j = 0; j < rad; j++)
			{
				int newCost = INDEX(g, i, k) + INDEX(g, k, j);
				if(INDEX(g, i, j) > newCost)
				{
					newG[i][j] = newCost;
				}
			}
		}

		memcpy(g->graph, newG, sizeof(int) * rad * rad);
	}
}

int main()
{
	int n;
	printf("Enter n: ");
	scanf("%d", &n);

	Graph_t g = Graph_init(n);

	while(true)
	{
		printf("Enter edges in order: v1, v2, weight [v1 = -1 is exit]:: ");
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		if(a == -1) break;

		Graph_edgeTo(&g, a, b, w, false);
	}

	printf("Entered graph:\n");
	Graph_print(&g);

	Graph_floyd(&g);

	printf("After floyd:\n");
	Graph_print(&g);

	Graph_free(&g);
}
