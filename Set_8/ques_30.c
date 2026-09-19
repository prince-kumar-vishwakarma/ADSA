#include <stdio.h>

int n = 5, e = 4;

/* Adjacency matrix */
int graph[5][5] = {
    {0,1,0,1,0},
    {1,0,1,0,0},
    {0,1,0,0,1},
    {1,0,0,0,1},
    {0,0,1,1,0}
};

int color[5];

/* Check whether graph is bipartite */
int isBipartite()
{
    int queue[5], front = 0, rear = 0;
    int i, j, u;

    for (i = 0; i < n; i++)
        color[i] = -1;

    color[0] = 0;
    queue[rear++] = 0;

    while (front < rear) {
        u = queue[front++];

        for (j = 0; j < n; j++) {
            if (graph[u][j] == 1) {

                if (color[j] == -1) {
                    color[j] = 1 - color[u];
                    queue[rear++] = j;
                }
                else if (color[j] == color[u]) {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int main()
{
    printf("n = %d, e = %d\n", n, e);

    if (isBipartite())
        printf("The graph is Bipartite.\n");
    else
        printf("The graph is not Bipartite.\n");

    return 0;
}

// n = 5, e = 4
// The graph is Bipartite.
