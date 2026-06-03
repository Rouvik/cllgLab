#include <stdio.h>
#include <time.h>
#include <sys/resource.h>

int main()
{
    int n, src;
    printf("n: ");
    scanf("%d", &n);

    int g[n][n];
    printf("Adjacency matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    printf("Source: ");
    scanf("%d", &src);

    clock_t st = clock();

    int dist[n], vis[n];
    for(int i = 0; i < n; i++)
        dist[i] = 9999, vis[i] = 0;

    dist[src] = 0;

    for(int k = 0; k < n - 1; k++)
    {
        int u = -1, mn = 9999;

        for(int i = 0; i < n; i++)
            if(!vis[i] && dist[i] < mn)
                mn = dist[i], u = i;

        vis[u] = 1;

        for(int v = 0; v < n; v++)
            if(g[u][v] && !vis[v] &&
               dist[u] + g[u][v] < dist[v])
                dist[v] = dist[u] + g[u][v];
    }

    clock_t en = clock();

    printf("Distances:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", dist[i]);

    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);

    printf("\nTime: %f sec",
           (double)(en - st) / CLOCKS_PER_SEC);
    printf("\nSpace: %ld KB\n",
           usage.ru_maxrss);
}