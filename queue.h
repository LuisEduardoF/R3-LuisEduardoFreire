#ifndef QUEUE
#define QUEUE

typedef struct queue *tQueue;

tQueue inicializeQueue();

void enqueue(void*, tQueue);
void* dequeue(tQueue);

int lenghtQueue(tQueue);

void freeQueue(tQueue);

#endif
