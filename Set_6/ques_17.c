#include <stdio.h>

#define N 4
#define INF 9999

void floydWarshall(int graph[N][N]) {
    int dist[N][N];

    // Copy graph to dist
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dist[i][j] = graph[i][j];

    // Floyd-Warshall
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    printf("Shortest distance matrix:\n");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[N][N] = {
        {0,   5,  INF, 10},
        {INF, 0,   3,  INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    floydWarshall(graph);

    return 0;
}

// Shortest distance matrix:
//   0   5   8   9
// INF   0   3   4
// INF INF   0   1
// INF INF INF   0
