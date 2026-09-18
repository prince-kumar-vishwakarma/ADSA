#include <stdio.h>

#define N 5

int graph[N][N] = {
    {0, 1, 1, 0, 0},
    {1, 0, 1, 1, 0},
    {1, 1, 0, 0, 1},
    {0, 1, 0, 0, 1},
    {0, 0, 1, 1, 0}
};

int visited[N], path[N];
int minCycle = N + 1, maxCycle = 0;

void DFS(int start, int u, int depth) {
    visited[u] = 1;
    path[depth] = u;

    for (int v = 0; v < N; v++) {
        if (graph[u][v]) {
            if (v == start && depth >= 2) {
                int len = depth + 1;

                if (len < minCycle) minCycle = len;
                if (len > maxCycle) maxCycle = len;
            }
            else if (!visited[v] && v >= start) {
                DFS(start, v, depth + 1);
            }
        }
    }

    visited[u] = 0;
}

int main() {
    for (int i = 0; i < N; i++)
        DFS(i, i, 0);

    if (maxCycle == 0)
        printf("No cycle found\n");
    else {
        printf("Smallest cycle length = %d\n", minCycle);
        printf("Largest cycle length = %d\n", maxCycle);
    }

    return 0;
}


// Smallest cycle length = 3
// Largest cycle length = 4
