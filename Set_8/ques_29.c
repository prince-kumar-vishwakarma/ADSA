#include <stdio.h>

int n = 5, e = 6;

/* Adjacency matrix */
int graph[5][5] = {
    {0,1,1,0,1},
    {1,0,1,1,0},
    {1,1,0,1,0},
    {0,1,1,0,1},
    {1,0,0,1,0}
};

int path[5];

/* Check whether vertex can be added */
int isSafe(int v, int pos){
    int i;
    if (graph[path[pos - 1]][v] == 0)
        return 0;

    for (i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;

    return 1;
}

/* Find Hamiltonian cycle */
int findCycle(int pos){
    int v;

    if (pos == n)
        return graph[path[n - 1]][path[0]];

    for (v = 1; v < n; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;

            if (findCycle(pos + 1))
                return 1;

            path[pos] = -1;
        }
    }

    return 0;
}

int main()
{
    int i;

    for (i = 0; i < n; i++)
        path[i] = -1;

    path[0] = 0;

    printf("n = %d, e = %d\n", n, e);

    if (findCycle(1)) {
        printf("Hamiltonian Cycle exists.\n");
        printf("Cycle: ");

        for (i = 0; i < n; i++)
            printf("%d -> ", path[i] + 1);

        printf("%d\n", path[0] + 1);
    }
    else {
        printf("Hamiltonian Cycle does not exist.\n");
    }

    return 0;
}


// n = 5, e = 6
// Hamiltonian Cycle exists.
// Cycle: 1 -> 2 -> 3 -> 4 -> 5 -> 1
