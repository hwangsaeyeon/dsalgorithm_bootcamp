#include <stdio.h>
#include <stdlib.h>

#include "cQueue.h"

QueueType* createCQueue(void) {
  QueueType* cQ;
  cQ = (QueueType*)malloc(sizeof(QueueType));
  cQ->front = 0;
  cQ->rear = 0;
  return cQ;
}

// Check whether queue is empty
int isEmpty(QueueType* cQ) {
    if(cQ->front==cQ->rear)
        return 1;
    else
        return 0;
}

// Check whether queue is full
int isFull(QueueType* cQ) {
    if (((cQ->rear+1) % cQ_SIZE) == cQ->front)
        return 1;
    else
        return 0;
}

// Push item at rear
void push(QueueType* cQ, element item) {
    if ((isFull(cQ)) == 1)
        printf("Queue is full!\n");
    else
    {
        cQ->rear = (cQ->rear+1) % cQ_SIZE;
        cQ->queue[cQ->rear] = item;
    }

}

// Return item at front and delete
element pop(QueueType* cQ) {
    if (isEmpty(cQ) == 1)
    {
        printf("Queue is empty!\n");
        return -1;
    }
    else
    {
        cQ->front = (cQ->front+1) % cQ_SIZE;
        return cQ->queue[cQ->front];
    }
}

// Return item at front
element front(QueueType* cQ) {
    if (isEmpty(cQ) == 1)
        return -1;
    return cQ->queue[(cQ->front+1)%cQ_SIZE];
}

// Return item at rear
element back(QueueType* cQ) {
    if (isEmpty(cQ) == 1)
        return -1;
    return cQ->queue[(cQ->rear)%cQ_SIZE];
}


// Print all items
void print(QueueType* cQ) {
    for(int i=cQ->front+1; i<=cQ->rear; i++)
    {
        printf("%d",cQ->queue[i]);
    }
    printf("\n");
}
