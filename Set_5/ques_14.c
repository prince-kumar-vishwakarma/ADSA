#include <stdio.h>

#define N 5

int graph[N][N] = {
    {0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0}
};

int color[N], start[N], finish[N], time = 0;

void DFS(int u) {
    color[u] = 1;              // Visiting
    start[u] = ++time;

    for (int v = 0; v < N; v++) {
        if (graph[u][v]) {
            if (color[v] == 0) {
                printf("%d -> %d : Tree Edge\n", u, v);
                DFS(v);
            }
            else if (color[v] == 1) {
                printf("%d -> %d : Back Edge\n", u, v);
            }
            else if (start[u] < start[v]) {
                printf("%d -> %d : Forward Edge\n", u, v);
            }
            else {
                printf("%d -> %d : Cross Edge\n", u, v);
            }
        }
    }

    color[u] = 2;              // Finished
    finish[u] = ++time;
}

int main() {
    for (int i = 0; i < N; i++)
        if (color[i] == 0)
            DFS(i);

    return 0;
}


// 0 -> 1 : Tree Edge
// 1 -> 2 : Tree Edge
// 2 -> 4 : Tree Edge
// 1 -> 3 : Tree Edge
// 3 -> 4 : Cross Edge
// 0 -> 2 : Forward Edge
