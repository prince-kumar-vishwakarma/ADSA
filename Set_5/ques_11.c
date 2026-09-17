#include <stdio.h>
#define INF 9999
#define N 5

void dijkstra(int graph[N][N], int src) {
    int dist[N], visited[N] = {0};
    int i, j, min, u;

    for (i = 0; i < N; i++)
        dist[i] = INF;
    dist[src] = 0;

    for (i = 0; i < N - 1; i++) {
        min = INF;

        for (j = 0; j < N; j++)
            if (!visited[j] && dist[j] < min)
                min = dist[j], u = j;

        visited[u] = 1;

        for (j = 0; j < N; j++)
            if (!visited[j] && graph[u][j] &&
                dist[u] + graph[u][j] < dist[j])
                dist[j] = dist[u] + graph[u][j];
    }

    for (i = 0; i < N; i++)
        printf("Distance to %d = %d\n", i, dist[i]);
}

int main() {
    int graph[N][N] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    dijkstra(graph, 0);
    return 0;
}
