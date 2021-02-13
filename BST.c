#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include "stack.h"
#include "queue.h"
struct bst{
    int n;
    tBst left, right;
};
int max(int a, int b){
    return b < a ? a : b;
}
int height(tBst n){
    if(n == NULL)
        return -1;
    else
        return max(height(n->left)+1, height(n->right) + 1);
}
tBst inicializeNode(int n){
    tBst new = malloc(sizeof(struct bst));
    new->n = n;
    new->left = new->right = NULL;
    return new;
}
tBst inicializeBST(){
    return NULL;
}
tBst insert(int n, tBst r){
    if(r == NULL){
        return inicializeNode(n);
    }
    if (n < r->n) 
        r->left = insert(n, r->left); 
    else if (n > r->n) 
        r->right = insert(n, r->right);

    return r; 
}


void DFS(tBst r){
    if(r != NULL){
        printf("%d\n", r->n);
        DFS(r->left);
        DFS(r->right);
    }
}
void non_recursiveDFS(tBst r){
    tStack s = inicializeStack();
    push(r, s);
    while(lenghtStack(s) > 0){
        tBst aux = pop(s);

        printf("%d\n", aux->n);

        if(aux->left != NULL)
            push(aux->left, s);
        if(aux->right != NULL)
            push(aux->right, s);
    }
    freeStack(s);
}

void postOrder(tBst r){
    if(r != NULL){
        DFS(r->left);
        printf("%d\n", r->n);
        DFS(r->right);
    }
}
void non_recursivePostOrder(tBst r){
}

void inOrder(tBst r){
    if(r != NULL){
        DFS(r->left);
        DFS(r->right);
        printf("%d\n", r->n);
    }
}
void non_recursiveInOrder(tBst);

void BFS(tBst r){
    tQueue s = inicializeQueue();
    enqueue(r, s);
    while(lenghtQueue(s) > 0){
        tBst aux = dequeue(s);
        
        printf("%d\n", aux->n);

        if(aux->left != NULL)
            enqueue(aux->left, s);
        if(aux->right != NULL)
            enqueue(aux->right, s);
    }
    freeQueue(s);
}

void printTree(tBst s, void f(tBst)){
    f(s);
}

void freeBST(tBst r){
    if(r != NULL){
        freeBST(r->left);
        freeBST(r->right);
        free(r);
    }
}