#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
typedef struct node{
    void* info;
    struct node *prox;
}*tNode;
tNode inicializeNodeQueue(void* info){
    tNode new = malloc(sizeof(struct node));
    new->info = info;
    new->prox = NULL;
    return new;
}
void freeNodeQueue(tNode t){
    free(t);
}
struct queue{
    tNode front, rear;
    int lenght;
};
int isEmptyQueue(tQueue q){
    return q->lenght == 0;
}
int ExistQueue(tQueue q){
    return q != NULL;
}
void* peekQueue(tQueue s){
    if(ExistQueue(s) && !isEmptyQueue(s))
        return s->front->info;
    return NULL;
}
tQueue inicializeQueue(){
    tQueue new = malloc(sizeof(struct queue));

    new->front = new->rear = NULL;
    new->lenght = 0;

    return new;
}

void enqueue(void* data, tQueue q){
    if(ExistQueue(q)){
        tNode new = inicializeNodeQueue(data);
        if(isEmptyQueue(q)){
            q->front = q->rear = new;
        }
        else{
            q->rear->prox = new;
            q->rear = new;
        }
        q->lenght++;
    }
}
void* dequeue(tQueue q){
    if(ExistQueue(q)){
        tNode p = q->front;
        if(!isEmptyQueue(q)){
            void* aux = p->info;

            q->front = q->front->prox;
            freeNodeQueue(p);
            q->lenght--;

            return aux;
        }
    }
    return NULL;
}

int lenghtQueue(tQueue q){
    if(ExistQueue(q))
        return q->lenght;
    return -1;
}
void freeQueue(tQueue q){
    if(ExistQueue(q)){
        tNode aux = NULL;
        for(tNode p = q->front; p != NULL; p = aux){
            aux = p->prox;
            freeNodeQueue(p);
        }
        free(q);
    }
}

