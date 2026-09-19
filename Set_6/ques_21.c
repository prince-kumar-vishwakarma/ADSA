#include <stdio.h>
#include <stdlib.h>

#define N 4

int goal[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};

int cost(int a[4][4]) {
    int c=0,i,j,x;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++) {
            x=a[i][j];
            if(x && (x-1)/4!=i) c++;
            if(x && (x-1)%4!=j) c++;
        }
    return c;
}

void solve(int a[4][4],int x,int y,int d) {
    int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
    int i,j,t,nx,ny;

    if(cost(a)==0) {
        printf("Solved in %d moves\n",d);
        return;
    }

    for(i=0;i<4;i++) {
        nx=x+dx[i]; ny=y+dy[i];

        if(nx>=0&&nx<4&&ny>=0&&ny<4) {
            t=a[x][y]; a[x][y]=a[nx][ny]; a[nx][ny]=t;

            solve(a,nx,ny,d+1);

            t=a[x][y]; a[x][y]=a[nx][ny]; a[nx][ny]=t;
        }
    }
}

int main() {
    int a[4][4],i,j,x,y;

    printf("Enter puzzle (0 for blank):\n");
    for(i=0;i<4;i++)
        for(j=0;j<4;j++) {
            scanf("%d",&a[i][j]);
            if(a[i][j]==0) x=i,y=j;
        }

    solve(a,x,y,0);
    return 0;
}

// Input:
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 0 14 15

// Output:-
// Moves: RR
// Number of moves = 2
