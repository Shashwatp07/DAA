#include <stdio.h>
#include <stdlib.h>
#define MAXV 100
#define MAXE 10000

typedef struct { int u, v, w; } Edge;
int parent[MAXV], rankSet[MAXV];

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}
int unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return 0;
    if (rankSet[a] < rankSet[b]) parent[a] = b;
    else if (rankSet[a] > rankSet[b]) parent[b] = a;
    else { parent[b] = a; rankSet[a]++; }
    return 1;
}
int compare(const void *a, const void *b) {
    const Edge *x = a, *y = b;
    return (x->w > y->w) - (x->w < y->w);
}
int main(void) {
    int V, E, total = 0, used = 0;
    Edge edges[MAXE];
    printf("Enter vertices and edges: ");
    scanf("%d%d", &V, &E);
    if (V <= 0 || V > MAXV || E < 0 || E > MAXE) return 1;
    printf("Enter each edge as: u v weight (vertices 0 to %d)\n", V - 1);
    for (int i = 0; i < E; i++)
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);

    for (int i = 0; i < V; i++) parent[i] = i, rankSet[i] = 0;
    qsort(edges, E, sizeof(Edge), compare);
    printf("Edges in MST:\n");
    for (int i = 0; i < E && used < V - 1; i++) {
        if (unite(edges[i].u, edges[i].v)) {
            printf("%d - %d : %d\n", edges[i].u, edges[i].v, edges[i].w);
            total += edges[i].w; used++;
        }
    }
    if (used != V - 1) printf("Graph is disconnected; MST does not exist.\n");
    else printf("Total MST weight = %d\n", total);
    return 0;
}
