#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *rear = NULL;

void enqueue(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = x;

    if (rear == NULL) {
        rear = n;
        n->next = n;
    } else {
        n->next = rear->next;
        rear->next = n;
        rear = n;
    }
}

void dequeue() {
    if (rear == NULL) {
        printf("Queue Empty\n");
        return;
    }

    struct Node *front = rear->next;
    printf("Deleted: %d\n", front->data);

    if (front == rear)
        rear = NULL;
    else
        rear->next = front->next;

    free(front);
}

void display() {
    if (rear == NULL) return;

    struct Node *p = rear->next;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != rear->next);
    printf("\n");
}

int main() {
    enqueue(10); enqueue(20); enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}
