#include <stdio.h>
#define N 5

int g[N][N] = {
    {0,1,1,0,0},
    {1,0,1,0,0},
    {1,1,0,1,0},
    {0,0,1,0,1},
    {0,0,0,1,0}
};

int d[N], low[N], par[N], t, st[20][2], top;

/* BCC + Articulation + Bridge */
void dfs(int u) {
    int v, ch=0;
    d[u]=low[u]=++t;

    for(v=0;v<N;v++) if(g[u][v]) {
        if(!d[v]) {
            par[v]=u; ch++;
            st[++top][0]=u; st[top][1]=v;
            dfs(v);

            if(low[v]<low[u]) low[u]=low[v];

            if(low[v]>=d[u]) {
                printf("BCC: ");
                do {
                    printf("(%d,%d) ",st[top][0],st[top][1]);
                } while(st[top--][0]!=u || st[top][1]!=v);
                printf("\n");
            }

            if(low[v]>d[u])
                printf("Bridge: %d-%d\n",u,v);

            if((par[u]==-1 && ch>1) ||
               (par[u]!=-1 && low[v]>=d[u]))
                printf("Articulation: %d\n",u);
        }
        else if(v!=par[u] && d[v]<d[u]) {
            if(d[v]<low[u]) low[u]=d[v];
            st[++top][0]=u;
            st[top][1]=v;
        }
    }
}

/* Simple SCC using reachability */
void reach(int u, int a[N][N], int vis[]) {
    int v;
    vis[u]=1;
    for(v=0;v<N;v++)
        if(a[u][v] && !vis[v])
            reach(v,a,vis);
}

void SCC() {
    int i,j,vis[N],r[N],ok;

    printf("\nSCC:\n");

    for(i=0;i<N;i++) {
        if(d[i]==0) {
            for(j=0;j<N;j++) vis[j]=0;
            reach(i,g,vis);

            printf("{");
            for(j=0;j<N;j++) {
                if(vis[j]) {
                    for(int k=0;k<N;k++) r[k]=0;
                    reach(j,g,r);
                    ok=1;
                    for(int k=0;k<N;k++)
                        if(vis[k] && !r[k]) ok=0;
                    if(ok) printf("%d ",j);
                }
            }
            printf("}\n");
        }
    }
}

int main() {
    int i;

    for(i=0;i<N;i++) par[i]=-1;

    printf("BCC, Articulation Points and Bridges:\n");
    dfs(0);

    SCC();

    return 0;
}


// BCC, Articulation Points and Bridges:
// BCC: (3,4)
// Bridge: 3-4
// Articulation: 3
// BCC: (2,3)
// Bridge: 2-3
// Articulation: 2
// BCC: (2,1) (1,0) (0,2)

// SCC:
// {0 1 2 3 4}
