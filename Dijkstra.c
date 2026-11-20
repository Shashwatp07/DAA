
#include <stdio.h>

#define INF 99999

void dijkstra(int graph[10][10], int n, int src)
{
    int dist[10], visited[10];
    int i, j, min, u;

    // Initialize distances and visited array
    for (i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (i = 0; i < n - 1; i++)
    {
        min = INF;
        u = -1;

        // Find minimum distance unvisited vertex
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        // Update adjacent vertices
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && graph[u][j] != 0 &&
                dist[u] + graph[u][j] < dist[j])
            {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", src);

    for (i = 0; i < n; i++)
    {
        if (dist[i] == INF)
            printf("%d -> %d = INF\n", src, i);
        else
            printf("%d -> %d = %d\n", src, i, dist[i]);
    }
}

int main()
{
    int graph[10][10];
    int n, src, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    dijkstra(graph, n, src);

    return 0;
}
