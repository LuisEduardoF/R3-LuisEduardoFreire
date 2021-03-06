#ifndef STACK
#define STACK

typedef struct stack *tStack;

tStack inicializeStack();
void* peekStack(tStack);

void push(void*, tStack);
void* pop(tStack);

int lenghtStack(tStack);

void freeStack(tStack);

#endif