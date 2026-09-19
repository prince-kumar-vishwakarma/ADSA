#include <stdio.h>
#include <time.h>

#define MAX 100
#define INF 999999

int cost[MAX][MAX], n;
int visited[MAX], minCost;

void tsp(int city, int count, int total) {
    int i;

    if (count == n) {
        if (cost[city][0] > 0 &&
            total + cost[city][0] < minCost)
            minCost = total + cost[city][0];
        return;
    }

    for (i = 0; i < n; i++) {
        if (!visited[i] && cost[city][i] > 0) {
            visited[i] = 1;
            tsp(i, count + 1, total + cost[city][i]);
            visited[i] = 0;
        }
    }
}

void solve(int size) {
    int i, j;
    clock_t start, end;

    n = size;

    /* Generate a simple graph */
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cost[i][j] = (i == j) ? 0 : (i + j) % 50 + 1;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    minCost = INF;
    visited[0] = 1;

    start = clock();
    tsp(0, 1, 0);
    end = clock();

    printf("%d\t%.6f\n", n,
           (double)(end - start) / CLOCKS_PER_SEC);
}

int main() {
    printf("Nodes\tTime(sec)\n");

    solve(10);
    solve(20);
    solve(40);
    solve(60);
    solve(100);

    return 0;
}
