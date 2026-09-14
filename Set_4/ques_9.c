#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

void preorder(struct Node *root) {
    if (root == NULL) return;

    struct Node *stack[100];
    int top = -1;

    stack[++top] = root;

    while (top != -1) {
        struct Node *temp = stack[top--];

        printf("%d ", temp->data);

        // Push right first so left is processed first
        if (temp->right)
            stack[++top] = temp->right;

        if (temp->left)
            stack[++top] = temp->left;
    }
}

int main() {
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Preorder: ");
    preorder(root);

    return 0;
}
