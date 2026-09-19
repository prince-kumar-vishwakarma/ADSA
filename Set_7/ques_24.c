#include <stdio.h>

int graph[10][10], color[10], n, m;

int safe(int v, int c) {
    int i;
    for (i = 0; i < n; i++)
        if (graph[v][i] && color[i] == c)
            return 0;
    return 1;
}

int solve(int v) {
    int c;

    if (v == n)
        return 1;

    for (c = 1; c <= m; c++) {
        if (safe(v, c)) {
            color[v] = c;

            if (solve(v + 1))
                return 1;

            color[v] = 0;   // Backtrack
        }
    }
    return 0;
}

int main() {
    int i, j;

    printf("Enter vertices: ");
    scanf("%d", &n);

    printf("Enter number of colors: ");
    scanf("%d", &m);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    if (solve(0)) {
        printf("Colors: ");
        for (i = 0; i < n; i++)
            printf("%d ", color[i]);
    } else
        printf("No solution");

    return 0;
}


// Enter vertices: 4
// Enter number of colors: 3
// Enter adjacency matrix:
// 0 1 1 0
// 1 0 1 1
// 1 1 0 1
// 0 1 1 0

// Colors: 1 2 3 1
