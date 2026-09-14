#include <stdio.h>

int q1[100], q2[100];
int f1 = 0, r1 = -1, f2 = 0, r2 = -1;

void enqueue(int x) {
    q1[++r1] = x;
}

int dequeue() {
    if (r1 < f1) {
        printf("Stack Empty\n");
        return -1;
    }

    while (f1 < r1)
        q2[++r2] = q1[f1++];

    int x = q1[f1++];

    f1 = 0;
    r1 = -1;

    while (f2 <= r2)
        q1[++r1] = q2[f2++];

    f2 = 0;
    r2 = -1;

    return x;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Popped: %d\n", dequeue());
    printf("Popped: %d\n", dequeue());

    return 0;
}
