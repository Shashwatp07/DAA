#include <stdio.h>
#define MAX 100
#define INF 1000000000

int main(void) {
    int n, source, graph[MAX][MAX], dist[MAX], visited[MAX] = {0};
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX) return 1;
    printf("Enter adjacency matrix (0 means no edge; weights must be non-negative):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &graph[i][j]);
    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);
    if (source < 0 || source >= n) return 1;

    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[source] = 0;
    for (int count = 0; count < n; count++) {
        int u = -1, best = INF;
        for (int i = 0; i < n; i++)
            if (!visited[i] && dist[i] < best) best = dist[i], u = i;
        if (u == -1) break;
        visited[u] = 1;
        for (int v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] > 0 &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printf("Shortest distances from %d:\n", source);
    for (int i = 0; i < n; i++)
        if (dist[i] == INF) printf("%d : unreachable\n", i);
        else printf("%d : %d\n", i, dist[i]);
    return 0;
}
