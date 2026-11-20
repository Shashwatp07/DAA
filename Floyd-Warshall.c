
#include <stdio.h>

#define INF 99999

void floydWarshall(int graph[10][10], int n)
{
    int dist[10][10];
    int i, j, k;

    // Copy original graph into distance matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshall algorithm
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (dist[i][k] != INF &&
                    dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] =
                        dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Check for negative weight cycle
    for (i = 0; i < n; i++)
    {
        if (dist[i][i] < 0)
        {
            printf("Negative weight cycle detected!\n");
            return;
        }
    }

    // Print shortest distance matrix
    printf("\nShortest Distance Matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int graph[10][10];
    int n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    printf("(Use 99999 for no edge)\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(graph, n);

    return 0;
}
