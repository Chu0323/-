#pragma once
#ifndef _LINEAR_QUEUE_H
#define _LINEAR_QUEUE_H

#include <iostream>
#include <string>
using namespace std;
typedef struct
{
	string name; //姓名
	string sex; //性别，'F'表示女性，'M'表示男性
} Person;

#define MAXSIZE 100

typedef struct
{
	Person* base;
	int front; //头指针
	int rear; //尾指针
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




