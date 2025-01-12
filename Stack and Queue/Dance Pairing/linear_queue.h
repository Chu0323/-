#pragma once
#ifndef _LINEAR_QUEUE_H
#define _LINEAR_QUEUE_H

#include <iostream>
#include <string>
using namespace std;
typedef struct
{
	string name; //����
	string sex; //�Ա�'F'��ʾŮ�ԣ�'M'��ʾ����
} Person;

#define MAXSIZE 100

typedef struct
{
	Person* base;
	int front; //ͷָ��
	int rear; //βָ��
} SqQueue;

void InitQueue(SqQueue& Q);
int QueueLength(SqQueue& Q);
int IsEmpty(SqQueue& Q);
int IsFull(SqQueue& Q);
int pushQueue(SqQueue& Q, Person& e);
int popQueue(SqQueue& Q, Person& e);
int GetHead(SqQueue& Q, Person& e);
int DeleteQueue(SqQueue& Q);
int ClearQueue(SqQueue& Q);
void DancePartner(SqQueue& Mdancers, SqQueue& Fdancers, Person dancer[], int num);


#endif




