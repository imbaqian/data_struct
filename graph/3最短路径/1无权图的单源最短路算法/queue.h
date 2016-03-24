

#ifndef QUEUE_H_
#define QUEUE_H_


typedef int QueueType;
struct QNode{
    QueueType* Q;   /*可变长度循环队列*/
    int rear; /*指向队列最后一个元素*/
    int front;/*指向队列第一个元素的前一个*/
    int size;
};
typedef struct QNode* Queue;

Queue CreateQueue(int MaxNum);
void AddQueue(Queue Q,QueueType item);
QueueType DeleteQueue(Queue Q);



#endif
