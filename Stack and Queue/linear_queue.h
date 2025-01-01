#pragma once
#ifndef _LINEAR_QUEUE_H
#define _LINEAR_QUEUE_H

#define MAXQSIZE 100 //最大队列长度
#define QElemType int
#define OVERFLOW -2

typedef struct
{
	QElemType* base; //初始化的动态分配存储空间
	int front; //头指针
	int rear; //尾指针
} SqQueue;
void InitQueue(SqQueue &Q);
int QueueLength(SqQueue& Q);
int IsEmpty(SqQueue& Q);
int pushQueue(SqQueue& Q, QElemType e);
int popQueue(SqQueue& Q, QElemType& e);
int GetHead(SqQueue& Q, QElemType& e);

#endif
