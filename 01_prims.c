#include <stdio.h>
#define MAX 100
#define INF 1000000000

int main(void) {
    int n, cost[MAX][MAX], selected[MAX] = {0};
    int edges = 0, total = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX) return 1;

    printf("Enter adjacency matrix (0 means no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    selected[0] = 1;
    printf("Edges in MST:\n");
    while (edges < n - 1) {
        int minimum = INF, u = -1, v = -1;
        for (int i = 0; i < n; i++) if (selected[i])
            for (int j = 0; j < n; j++)
                if (!selected[j] && cost[i][j] != 0 && cost[i][j] < minimum) {
                    minimum = cost[i][j]; u = i; v = j;
                }

        if (u == -1) {
            printf("Graph is disconnected; MST does not exist.\n");
            return 0;
        }
        printf("%d - %d : %d\n", u, v, minimum);
        total += minimum;
        selected[v] = 1;
        edges++;
    }
    printf("Total MST weight = %d\n", total);
    return 0;
}
