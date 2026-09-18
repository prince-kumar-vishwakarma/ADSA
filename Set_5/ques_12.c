#include <stdio.h>
#define INF 9999
#define N 5

int main() {
    int graph[N][N] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int selected[N] = {0};
    int edges = 0, min, x, y, cost = 0;

    selected[0] = 1;

    printf("Edges in Minimum Spanning Tree:\n");

    while (edges < N - 1) {
        min = INF;

        for (int i = 0; i < N; i++)
            if (selected[i])
                for (int j = 0; j < N; j++)
                    if (!selected[j] && graph[i][j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }

        printf("%d - %d : %d\n", x, y, min);
        cost += min;
        selected[y] = 1;
        edges++;
    }

    printf("Minimum Cost = %d\n", cost);

    return 0;
}


// Edges in Minimum Spanning Tree:
// 0 - 1 : 2
// 1 - 2 : 3
// 1 - 4 : 5
// 0 - 3 : 6
// Minimum Cost = 16
