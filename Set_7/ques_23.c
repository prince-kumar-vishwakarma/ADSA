#include <stdio.h>

struct Job {
    char id;
    int deadline, profit;
};

void jobSequencing(struct Job a[], int n) {
    int slot[10] = {0};
    int i, j;

    // Sort by profit
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (a[i].profit < a[j].profit) {
                struct Job t = a[i];
                a[i] = a[j];
                a[j] = t;
            }

    // Schedule jobs
    for (i = 0; i < n; i++)
        for (j = a[i].deadline; j >= 1; j--)
            if (slot[j] == 0) {
                slot[j] = i + 1;
                printf("%c ", a[i].id);
                break;
            }
}

int main() {
    struct Job a[] = {
        {'A', 2, 100},
        {'B', 1, 19},
        {'C', 2, 27},
        {'D', 1, 25},
        {'E', 3, 15}
    };

    jobSequencing(a, 5);
    return 0;
}

// A C E
