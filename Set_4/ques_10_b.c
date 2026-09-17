// Red black tree
#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0

typedef struct R {
    int key, color;
    struct R *l,*r,*p;
} R;

R *NIL;

R* createTree() {
    NIL=malloc(sizeof(R));
    NIL->color=BLACK;
    NIL->l=NIL->r=NIL->p=NIL;
    return NIL;
}

R* newNode(int x) {
    R *n=malloc(sizeof(R));
    n->key=x; n->color=RED;
    n->l=n->r=n->p=NIL;
    return n;
}

void rotateLeft(R **root,R *x) {
    R *y=x->r;
    x->r=y->l;
    if(y->l!=NIL) y->l->p=x;
    y->p=x->p;

    if(x->p==NIL) *root=y;
    else if(x==x->p->l) x->p->l=y;
    else x->p->r=y;

    y->l=x; x->p=y;
}

void rotateRight(R **root,R *y) {
    R *x=y->l;
    y->l=x->r;
    if(x->r!=NIL) x->r->p=y;
    x->p=y->p;

    if(y->p==NIL) *root=x;
    else if(y==y->p->l) y->p->l=x;
    else y->p->r=x;

    x->r=y; y->p=x;
}

void insertFix(R **root,R *z) {
    while(z->p->color==RED) {
        if(z->p==z->p->p->l) {
            R *y=z->p->p->r;
            if(y->color==RED) {
                z->p->color=BLACK; y->color=BLACK;
                z->p->p->color=RED; z=z->p->p;
            } else {
                if(z==z->p->r) z=z->p,rotateLeft(root,z);
                z->p->color=BLACK; z->p->p->color=RED;
                rotateRight(root,z->p->p);
            }
        } else {
            R *y=z->p->p->l;
            if(y->color==RED) {
                z->p->color=BLACK; y->color=BLACK;
                z->p->p->color=RED; z=z->p->p;
            } else {
                if(z==z->p->l) z=z->p,rotateRight(root,z);
                z->p->color=BLACK; z->p->p->color=RED;
                rotateLeft(root,z->p->p);
            }
        }
    }
    (*root)->color=BLACK;
}

void insertItem(R **root,int x) {
    R *z=newNode(x), *y=NIL, *p=*root;

    while(p!=NIL) {
        y=p;
        p=x<p->key?p->l:p->r;
    }

    z->p=y;
    if(y==NIL) *root=z;
    else if(x<y->key) y->l=z;
    else y->r=z;

    insertFix(root,z);
}

R* searchItem(R *p,int x) {
    while(p!=NIL && p->key!=x)
        p=x<p->key?p->l:p->r;
    return p;
}


void deleteTree(R *p) {
    if(p==NIL) return;
    deleteTree(p->l);
    deleteTree(p->r);
    free(p);
}
