// B+ Tree

#include <stdio.h>
#include <stdlib.h>

#define ORDER 3

typedef struct BPNode {
    int key[ORDER];
    struct BPNode *child[ORDER+1];
    struct BPNode *next;
    int n, leaf;
} BPNode;

BPNode *bproot = NULL;

BPNode *createTree() {
    BPNode *p = malloc(sizeof(BPNode));
    p->n = 0;
    p->leaf = 1;
    p->next = NULL;
    return p;
}

void insertItem(BPNode *root, int k) {
    int i = root->n - 1;

    /* Leaf insertion */
    if (root->leaf) {
        while (i >= 0 && root->key[i] > k) {
            root->key[i+1] = root->key[i];
            i--;
        }
        root->key[i+1] = k;
        root->n++;
        return;
    }

    while (i >= 0 && k < root->key[i])
        i--;

    insertItem(root->child[i+1], k);
}

BPNode *serachItem(BPNode *root, int k) {
    int i = 0;

    while (i < root->n && k > root->key[i])
        i++;

    if (root->leaf) {
        if (i < root->n && root->key[i] == k)
            return root;
        return NULL;
    }

    return serachItem(root->child[i], k);
}

void deleteItem(BPNode *root, int k) {
    int i = 0;

    if (root->leaf) {
        while (i < root->n && root->key[i] != k)
            i++;

        if (i < root->n) {
            for (int j = i; j < root->n-1; j++)
                root->key[j] = root->key[j+1];

            root->n--;
        }
        return;
    }

    while (i < root->n && k >= root->key[i])
        i++;

    deleteItem(root->child[i], k);
}

void deleteTree(BPNode *root) {
    if (!root) return;

    if (!root->leaf)
        for (int i = 0; i <= root->n; i++)
            deleteTree(root->child[i]);

    free(root);
}
