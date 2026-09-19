#include <stdio.h>

int n = 5, e = 7, m = 3;

/* Adjacency matrix */
int graph[5][5] = {
    {0,1,1,0,1},
    {1,0,1,1,0},
    {1,1,0,1,1},
    {0,1,1,0,1},
    {1,0,1,1,0}
};

int clique[5];

/* Check whether selected vertices form a clique */
int isClique(int k) {
    int i, j;

    for (i = 0; i < k; i++)
        for (j = i + 1; j < k; j++)
            if (graph[clique[i]][clique[j]] == 0)
                return 0;

    return 1;
}

/* Try all combinations of vertices */
int findClique(int start, int k) {
    int i;

    if (k == m)
        return isClique(k);

    for (i = start; i < n; i++) {
        clique[k] = i;

        if (findClique(i + 1, k + 1))
            return 1;
    }

    return 0;
}

int main() {
    printf("n = %d, e = %d, m = %d\n", n, e, m);

    if (findClique(0, 0))
        printf("Clique of size %d exists.\n", m);
    else
        printf("Clique of size %d does not exist.\n", m);

    return 0;
}


// n = 5, e = 7, m = 3
// Clique of size 3 exists.
