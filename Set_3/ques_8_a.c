#include <stdio.h>

int q1[100], q2[100];
int f1 = 0, r1 = -1, f2 = 0, r2 = -1;

void enqueue(int x) {
    while (f1 <= r1)
        q2[++r2] = q1[f1++];

    q1[++r1] = x;

    while (f2 <= r2)
        q1[++r1] = q2[f2++];

    f1 = 0; f2 = 0;
    r2 = -1;
}

int dequeue() {
    if (r1 < f1) {
        printf("Stack Empty\n");
        return -1;
    }
    return q1[f1++];
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Popped: %d\n", dequeue());
    printf("Popped: %d\n", dequeue());

    return 0;
}
