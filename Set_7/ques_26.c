#include <stdio.h>

#define N 6

int g[N][N] = {
    {0,1,1,0,0,0},
    {0,0,0,1,0,0},
    {0,0,0,1,1,0},
    {0,0,0,0,0,1},
    {0,0,0,0,0,1},
    {0,0,0,0,0,0}
};

int visited[N], stack[N], top = -1;

void dfs(int v) {
    int i;

    visited[v] = 1;

    for(i = 0; i < N; i++)
        if(g[v][i] && !visited[i])
            dfs(i);

    stack[++top] = v;
}

void topologicalSort() {
    int i;

    for(i = 0; i < N; i++)
        if(!visited[i])
            dfs(i);

    printf("Topological Order: ");

    while(top >= 0)
        printf("%d ", stack[top--]);
}

int main() {
    topologicalSort();
    return 0;
}


// Topological Order: 0 2 1 4 3 5
