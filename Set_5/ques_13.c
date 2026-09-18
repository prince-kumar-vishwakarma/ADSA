#include <stdio.h>

int parent[5];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int a, int b) {
    parent[find(a)] = find(b);
}

int main() {
    int edges[][3] = {
        {0, 1, 2},
        {1, 2, 3},
        {1, 4, 5},
        {0, 3, 6},
        {2, 4, 7},
        {1, 3, 8},
        {3, 4, 9}
    };

    int n = 5, e = 7, count = 0, cost = 0;

    for (int i = 0; i < n; i++)
        parent[i] = i;

    // Sort edges by weight
    for (int i = 0; i < e - 1; i++)
        for (int j = i + 1; j < e; j++)
            if (edges[i][2] > edges[j][2]) {
                int temp[3];
                for (int k = 0; k < 3; k++)
                    temp[k] = edges[i][k], edges[i][k] = edges[j][k],
                    edges[j][k] = temp[k];
            }

    printf("Edges in MST:\n");

    for (int i = 0; i < e && count < n - 1; i++) {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];

        if (find(u) != find(v)) {
            printf("%d - %d : %d\n", u, v, w);
            cost += w;
            unionSet(u, v);
            count++;
        }
    }

    printf("Minimum Cost = %d\n", cost);

    return 0;
}


// Edges in MST:
// 0 - 1 : 2
// 1 - 2 : 3
// 1 - 4 : 5
// 0 - 3 : 6
// Minimum Cost = 16
