// AVL Tree
#include <stdio.h>
#include <stdlib.h>

typedef struct N {
    int key, h;
    struct N *l, *r;
} N;

int H(N *p) { return p ? p->h : 0; }
int max(int a,int b) { return a>b?a:b; }

N* createTree() { return NULL; }

N* newNode(int x) {
    N *p=malloc(sizeof(N));
    p->key=x; p->h=1; p->l=p->r=NULL;
    return p;
}

N* right(N *y) {
    N *x=y->l, *t=x->r;
    x->r=y; y->l=t;
    y->h=1+max(H(y->l),H(y->r));
    x->h=1+max(H(x->l),H(x->r));
    return x;
}

N* left(N *x) {
    N *y=x->r, *t=y->l;
    y->l=x; x->r=t;
    x->h=1+max(H(x->l),H(x->r));
    y->h=1+max(H(y->l),H(y->r));
    return y;
}

N* insertItem(N *p,int x) {
    if(!p) return newNode(x);
    if(x<p->key) p->l=insertItem(p->l,x);
    else if(x>p->key) p->r=insertItem(p->r,x);
    else return p;

    p->h=1+max(H(p->l),H(p->r));
    int b=H(p->l)-H(p->r);

    if(b>1 && x<p->l->key) return right(p);
    if(b<-1 && x>p->r->key) return left(p);
    if(b>1 && x>p->l->key) {
        p->l=left(p->l); return right(p);
    }
    if(b<-1 && x<p->r->key) {
        p->r=right(p->r); return left(p);
    }
    return p;
}

N* minNode(N *p) {
    while(p->l) p=p->l;
    return p;
}

N* deleteItem(N *p,int x) {
    if(!p) return NULL;

    if(x<p->key) p->l=deleteItem(p->l,x);
    else if(x>p->key) p->r=deleteItem(p->r,x);
    else {
        if(!p->l || !p->r) {
            N *t=p->l?p->l:p->r;
            if(!t) { free(p); return NULL; }
            *p=*t; free(t);
        } else {
            N *t=minNode(p->r);
            p->key=t->key;
            p->r=deleteItem(p->r,t->key);
        }
    }

    p->h=1+max(H(p->l),H(p->r));
    int b=H(p->l)-H(p->r);

    if(b>1 && H(p->l->l)>=H(p->l->r)) return right(p);
    if(b>1) { p->l=left(p->l); return right(p); }
    if(b<-1 && H(p->r->r)>=H(p->r->l)) return left(p);
    if(b<-1) { p->r=right(p->r); return left(p); }
    return p;
}

N* searchItem(N *p,int x) {
    if(!p || p->key==x) return p;
    return x<p->key ? searchItem(p->l,x) : searchItem(p->r,x);
}

void deleteTree(N *p) {
    if(!p) return;
    deleteTree(p->l); deleteTree(p->r);
    free(p);
}
