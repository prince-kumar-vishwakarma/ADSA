#include <stdio.h>
#define N 5

int q[N], front = -1, rear = -1;

void enqueue(int x) {
    if ((rear + 1) % N == front)
        printf("Queue Full\n");
    else {
        if (front == -1) front = 0;
        rear = (rear + 1) % N;
        q[rear] = x;
    }
}

void dequeue() {
    if (front == -1)
        printf("Queue Empty\n");
    else {
        printf("Deleted: %d\n", q[front]);
        if (front == rear) front = rear = -1;
        else front = (front + 1) % N;
    }
}

void display() {
    if (front == -1) return;
    int i = front;
    do {
        printf("%d ", q[i]);
        i = (i + 1) % N;
    } while (i != (rear + 1) % N);
    printf("\n");
}

int main() {
    enqueue(10); enqueue(20); enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}
