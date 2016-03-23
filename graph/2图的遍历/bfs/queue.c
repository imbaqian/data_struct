#include "queue.h"
#include <malloc.h>
#include <stdio.h>
Queue CreateQueue(int MaxNum)
{
    Queue newQueue =(Queue)malloc(sizeof(struct QNode));
    newQueue->rear = 0;
    newQueue->front = 0;
    newQueue->size = MaxNum;
    newQueue->Q = (QueueType*)malloc(MaxNum * sizeof(QueueType));
    return newQueue;
}


void AddQueue(Queue Q,QueueType item)
{
    if((Q->front + 1)%Q->size == Q->rear){
        print("Queue is full !");
        return;
    }
    Q->Q[ (Q->rear + 1)%Q->size ] = item; 
}


QueueType DeleteQueue(Queue Q)
{
    if( Q->rear == Q->front ){
        printf("Queue is empty !");
        return -1;
    }
    Q->front = (Q->front + 1)%Q->size;
    return Q->Q[Q->front];
}
