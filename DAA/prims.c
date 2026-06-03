#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <sys/resource.h>

#define INDEX(g, i, j) (g->mat[g->radius * i + j])

typedef struct Graph
{
    int radius;
    int *mat;
} Graph_t;

Graph_t Graph_init(int radius)
{
    return (Graph_t){
        .radius = radius,
        .mat = calloc(radius * radius, sizeof(int))};
}

void Graph_free(Graph_t *g)
{
    free(g->mat);
    g->radius = 0;
    g->mat = NULL;
}

void Graph_addEdge(Graph_t *g, int a, int b, int w)
{
    INDEX(g, a, b) = w;
    INDEX(g, b, a) = w;
}

void Graph_prims(Graph_t *g)
{
    int weights[g->radius];
    for (int i = 0; i < g->radius; i++)
    {
        weights[i] = 999;
    }

    int prev[g->radius];
    bool visited[g->radius];

    // assume start already visited and has previous as itself
    visited[0] = true;
    prev[0] = 0;

    int visitCount = 1;
    int current = 0; // current node to visit
    while (visitCount++ < g->radius)
    {
        int minVisitable = -1;
        int minVisitableWeight = 999;
        for (int i = 1; i < g->radius; i++)
        {
            int visitableWeight = INDEX(g, current, i);
            if (visitableWeight > 0 && !visited[i])
            {
                if (weights[i] > visitableWeight)
                {
                    weights[i] = visitableWeight;
                    prev[i] = current;
                }

                if (minVisitableWeight > visitableWeight)
                {
                    minVisitableWeight = visitableWeight;
                    minVisitable = i;
                }
            }
        }

        if (minVisitable == -1)
        {
            break;
        }

        current = minVisitable;
        visited[minVisitable] = true;
    }

    printf("Weights:\n");
    for (int i = 0; i < g->radius; i++)
    {
        printf("%d ", weights[i]);
    }

    printf("\nPrevious:\n");
    for (int i = 0; i < g->radius; i++)
    {
        printf("%d ", prev[i]);
    }

    printf("\n");
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    Graph_t g = Graph_init(n);

    while (true)
    {
        int a, b, w;
        printf("Enter a, b and weight: ");
        scanf("%d %d %d", &a, &b, &w);

        if (a == -1)
        {
            break;
        }

        Graph_addEdge(&g, a, b, w);
    };

    clock_t st = clock();
    Graph_prims(&g);
    clock_t end = clock();

    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);

    printf("Time: %f\nSpace: %ld\n", (double)(end - st) / CLOCKS_PER_SEC, usage.ru_maxrss);

    Graph_free(&g);
    return 0;
}