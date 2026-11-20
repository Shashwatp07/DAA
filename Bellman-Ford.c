
#include <stdio.h>

#define INF 99999

struct Edge
{
    int src, dest, weight;
};

void bellmanFord(struct Edge edges[], int V, int E, int src)
{
    int dist[10];
    int i, j;

    // Initialize distances
    for (i = 0; i < V; i++)
        dist[i] = INF;

    dist[src] = 0;

    // Relax all edges V-1 times
    for (i = 1; i <= V - 1; i++)
    {
        for (j = 0; j < E; j++)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if (dist[u] != INF &&
                dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycle
    for (j = 0; j < E; j++)
    {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;

        if (dist[u] != INF &&
            dist[u] + w < dist[v])
        {
            printf("Negative weight cycle detected!\n");
            return;
        }
    }

    // Print shortest distances
    printf("\nShortest distances from vertex %d:\n", src);

    for (i = 0; i < V; i++)
    {
        if (dist[i] == INF)
            printf("%d -> %d = INF\n", src, i);
        else
            printf("%d -> %d = %d\n", src, i, dist[i]);
    }
}

int main()
{
    int V, E, src, i;
    struct Edge edges[100];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (source destination weight):\n");

    for (i = 0; i < E; i++)
    {
        scanf("%d %d %d",
              &edges[i].src,
              &edges[i].dest,
              &edges[i].weight);
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    bellmanFord(edges, V, E, src);

    return 0;
}
