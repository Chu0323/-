#pragma once
#ifndef _LINEAR_QUEUE_H
#define _LINEAR_QUEUE_H

#define MAXQSIZE 100 //�����г���
#define QElemType int
#define OVERFLOW -2

typedef struct
{
	QElemType* base; //��ʼ���Ķ�̬����洢�ռ�
	int front; //ͷָ��
	int rear; //βָ��
} SqQueue;
void InitQueue(SqQueue &Q);
int QueueLength(SqQueue& Q);
int IsEmpty(SqQueue& Q);
int pushQueue(SqQueue& Q, QElemType e);
int popQueue(SqQueue& Q, QElemType& e);
int GetHead(SqQueue& Q, QElemType& e);

#endif