#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
typedef struct node{
    void* info;
    struct node *prox;
}*tNode;
tNode inicializeNodeStack(void* info){
    tNode new = malloc(sizeof(struct node));
    new->info = info;
    new->prox = NULL;
    return new;
}
void freeNodeStack(tNode t){
    free(t);
}
struct stack{
    tNode top;
    int lenght;
};
int isEmptyStack(tStack s){
    return s->lenght == 0;
}
int ExistStack(tStack s){
    return s != NULL;
}
tStack inicializeStack(){
    tStack new = malloc(sizeof(struct stack));

    new->top = NULL;
    new->lenght = 0;

    return new;
}

void push(void* data, tStack s){
    if(ExistStack(s)){
        tNode new = inicializeNodeStack(data);

        new->prox = s->top;
        s->top = new;

        s->lenght++;
    }
}
void* pop(tStack s){
    if(ExistStack(s)){
        tNode p = s->top;
        if(!isEmptyStack(s)){
            void* aux = p->info;
            s->top = s->top->prox;
            freeNodeStack(p);

            s->lenght--;
            return aux;
        }
    }
    return NULL;
}

int lenghtStack(tStack s){
    if(ExistStack(s))
        return s->lenght;
    return -1;
}
void freeStack(tStack s){
    if(ExistStack(s)){
        tNode aux = NULL;
        for(tNode p = s->top; p != NULL; p = aux){
            aux = p->prox;
            freeNodeStack(p);
        }
        free(s);
    }
}

