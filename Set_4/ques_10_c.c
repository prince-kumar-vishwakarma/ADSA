// B Tree

#include <stdio.h>
#include <stdlib.h>

#define T 2   // Minimum degree

typedef struct BNode {
    int key[2*T-1];
    struct BNode *child[2*T];
    int n, leaf;
} BNode;

BNode *root = NULL;

BNode *createTree() {
    BNode *p = malloc(sizeof(BNode));
    p->n = 0;
    p->leaf = 1;
    return p;
}

void splitChild(BNode *x, int i) {
    BNode *y = x->child[i];
    BNode *z = createTree();
    z->leaf = y->leaf;
    z->n = T - 1;

    for (int j = 0; j < T-1; j++)
        z->key[j] = y->key[j+T];

    if (!y->leaf)
        for (int j = 0; j < T; j++)
            z->child[j] = y->child[j+T];

    y->n = T - 1;

    for (int j = x->n; j >= i+1; j--)
        x->child[j+1] = x->child[j];

    x->child[i+1] = z;

    for (int j = x->n-1; j >= i; j--)
        x->key[j+1] = x->key[j];

    x->key[i] = y->key[T-1];
    x->n++;
}

void insertItem(BNode *x, int k) {
    int i = x->n - 1;

    if (x->leaf) {
        while (i >= 0 && k < x->key[i]) {
            x->key[i+1] = x->key[i];
            i--;
        }
        x->key[i+1] = k;
        x->n++;
    } else {
        while (i >= 0 && k < x->key[i]) i--;
        i++;

        if (x->child[i]->n == 2*T-1) {
            splitChild(x, i);
            if (k > x->key[i]) i++;
        }
        insertItem(x->child[i], k);
    }
}

void insert(int k) {
    if (root == NULL)
        root = createTree();

    if (root->n == 2*T-1) {
        BNode *s = createTree();
        s->leaf = 0;
        s->child[0] = root;
        root = s;
        splitChild(s, 0);
    }
    insertItem(root, k);
}

BNode *serachItem(BNode *x, int k) {
    int i = 0;
    while (i < x->n && k > x->key[i]) i++;

    if (i < x->n && k == x->key[i])
        return x;

    if (x->leaf)
        return NULL;

    return serachItem(x->child[i], k);
}

/* Simple deletion for demonstration */
void deleteItem(BNode *x, int k) {
    int i = 0;

    while (i < x->n && k > x->key[i]) i++;

    if (i < x->n && k == x->key[i]) {
        if (x->leaf) {
            for (int j = i; j < x->n-1; j++)
                x->key[j] = x->key[j+1];
            x->n--;
        }
        return;
    }

    if (!x->leaf)
        deleteItem(x->child[i], k);
}

void deleteTree(BNode *x) {
    if (!x) return;

    if (!x->leaf)
        for (int i = 0; i <= x->n; i++)
            deleteTree(x->child[i]);

    free(x);
}
