#include <stdio.h>
#include <time.h>
#include <sys/resource.h>

typedef struct
{
    int u, v, w;
} Edge;

int main()
{
    int V, E, src;

    printf("Vertices Edges: ");
    scanf("%d %d", &V, &E);

    Edge edges[E];

    printf("u v weight:\n");
    for(int i = 0; i < E; i++)
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].w);

    printf("Source: ");
    scanf("%d", &src);

    clock_t st = clock();

    int dist[V];
    for(int i = 0; i < V; i++)
        dist[i] = 9999;

    dist[src] = 0;

    for(int i = 1; i < V; i++)
        for(int j = 0; j < E; j++)
            if(dist[edges[j].u] != 9999 &&
               dist[edges[j].u] + edges[j].w < dist[edges[j].v])
                dist[edges[j].v] =
                    dist[edges[j].u] + edges[j].w;

    int neg = 0;
    for(int j = 0; j < E; j++)
        if(dist[edges[j].u] != 9999 &&
           dist[edges[j].u] + edges[j].w < dist[edges[j].v])
            neg = 1;

    clock_t en = clock();

    if(neg)
        printf("Negative cycle detected\n");
    else
    {
        printf("Distances:\n");
        for(int i = 0; i < V; i++)
            printf("%d ", dist[i]);
        putchar('\n');
    }

    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);

    printf("Time: %f sec\n",
           (double)(en - st) / CLOCKS_PER_SEC);

    printf("Space: %ld KB\n",
           usage.ru_maxrss);

    return 0;
}