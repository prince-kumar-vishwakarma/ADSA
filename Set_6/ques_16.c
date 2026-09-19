#include <stdio.h>

#define V 5
#define E 8
#define INF 9999

struct Edge {
    int u, v, w;
};

void bellmanFord(struct Edge edges[], int src) {
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i < V; i++)
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }

    // Check for negative cycle
    for (int j = 0; j < E; j++)
        if (dist[edges[j].u] != INF &&
            dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
            printf("Negative cycle exists!\n");
            return;
        }

    printf("Shortest distances from vertex %d:\n", src);

    for (int i = 0; i < V; i++)
        printf("%d -> %d = %d\n", src, i, dist[i]);
}

int main() {
    struct Edge edges[E] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    bellmanFord(edges, 0);

    return 0;
}


// Shortest distances from vertex 0:
// 0 -> 0 = 0
// 0 -> 1 = -1
// 0 -> 2 = 2
// 0 -> 3 = -2
// 0 -> 4 = 1
