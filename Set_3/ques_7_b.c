#include <stdio.h>

int s1[100], s2[100], t1 = -1, t2 = -1;

void push1(int x) { s1[++t1] = x; }
int pop1() { return s1[t1--]; }
void push2(int x) { s2[++t2] = x; }
int pop2() { return s2[t2--]; }

void enqueue(int x) {
    push1(x);
}

int dequeue() {
    if (t1 == -1 && t2 == -1) {
        printf("Queue Empty\n");
        return -1;
    }

    if (t2 == -1)
        while (t1 != -1)
            push2(pop1());

    return pop2();
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Deleted: %d\n", dequeue());
    printf("Deleted: %d\n", dequeue());

    return 0;
}
