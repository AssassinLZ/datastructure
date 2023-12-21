#include <iostream>

#define MaxSize 50

typedef struct//顺序队列
{
    char data[MaxSize];
    int front, rear;
} SqQueue;

typedef struct//链式队列结点 
{
    char data;
    struct LinkNode *next;
}LinkNode;

typedef struct //链式队列
{
    LinkNode *front,*rear;//队列的队头指针和队尾指针
}LinkQueue;


void InitQueue(SqQueue &Q)
{
    Q.rear = Q.front = 0;
}

bool isEmpty(SqQueue Q)
{
    if (Q.rear == Q.front)
        return false;
    else
        return true;
}

bool EnQueue(SqQueue &Q, char x)
{
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q, char &x)
{
    if (Q.rear == Q.front)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}