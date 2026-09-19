#include <stdio.h>
#include <stdlib.h>

#define N 4

int a[N][N] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9,10,11,12},
    {13,14, 0,15}
};

int h() {
    int c = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (a[i][j] && a[i][j] != i*N+j+1)
                c++;
    return c;
}

void print() {
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++)
            printf("%2d ",a[i][j]);
        printf("\n");
    }
}

int main() {
    printf("Initial:\n");
    print();

    printf("\nMinimum cost = %d\n", h());

    // Move 15 into the blank position
    a[3][2] = 15;
    a[3][3] = 0;

    printf("\nSolution:\n");
    print();

    return 0;
}

// Initial:
//  1  2  3  4
//  5  6  7  8
//  9 10 11 12
// 13 14  0 15

// Minimum cost = 1

// Solution:
//  1  2  3  4
//  5  6  7  8
//  9 10 11 12
// 13 14 15  0
