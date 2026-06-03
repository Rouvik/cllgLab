#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>

typedef struct
{
    int u, v, w;
} Edge;

int cmp(const void *a, const void *b)
{
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

int find(int parent[], int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent, parent[x]);
}

void unite(int parent[], int a, int b)
{
    parent[find(parent, a)] = find(parent, b);
}

void kruskal(Edge edges[], int V, int E)
{
    qsort(edges, E, sizeof(Edge), cmp);

    int parent[V];
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int cost = 0;

    printf("\nMST Edges:\n");

    for (int i = 0; i < E; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(parent, u) != find(parent, v))
        {
            printf("%d -- %d (%d)\n", u, v, edges[i].w);

            cost += edges[i].w;
            unite(parent, u, v);
        }
    }

    printf("Total Cost: %d\n", cost);
}

int main()
{
    int V, E;

    printf("Vertices: ");
    scanf("%d", &V);

    printf("Edges: ");
    scanf("%d", &E);

    Edge edges[E];

    printf("Enter u v weight:\n");
    for (int i = 0; i < E; i++)
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].w);

    clock_t st = clock();
    kruskal(edges, V, E);
    clock_t en = clock();

    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);

    printf("\nTime: %f sec\n",
           (double)(en - st) / CLOCKS_PER_SEC);

    printf("Space: %ld KB\n",
           usage.ru_maxrss);

    return 0;
}