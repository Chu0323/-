#include <iostream>
#include <cstdlib>
#include "linear_queue.h"
using namespace std;
//线性队列初始化
void InitQueue(SqQueue& Q)
{
	Q.base = new Person[MAXSIZE];
	if (!Q.base)
		exit(OVERFLOW);
	Q.front = 0;
	Q.rear = Q.front;
}
//返回队列的长度
int QueueLength(SqQueue& Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}
//判断队列是否为空
int IsEmpty(SqQueue& Q)
{
	if (Q.front == Q.rear)
		return true;
	return false;
}
//判断队列是否已满
int IsFull(SqQueue& Q)
{
	if ((Q.rear + 1) % MAXSIZE == Q.front)
		return true;
	return false;
}
//入队
int pushQueue(SqQueue& Q, Person& e)
{
	if ((Q.rear + 1) % MAXSIZE == Q.front) //队满
		return false;
	Q.base[Q.rear].name = e.name;
	Q.base[Q.rear].sex = e.sex;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return true;
}
//出队
int popQueue(SqQueue& Q, Person& e)
{
	if (IsEmpty(Q))
		return false;
	e.name = Q.base[Q.front].name;
	e.sex = Q.base[Q.front].sex;
	Q.front = (Q.front + 1) % MAXSIZE;
	return true;
}
//获取头元素
int GetHead(SqQueue& Q, Person& e)
{
	if (IsEmpty(Q))
		return false;
	e = Q.base[Q.front];
	return true;
}
//销毁队列
int DeleteQueue(SqQueue& Q)
{
	delete[] Q.base;
	Q.base = NULL;
	Q.front = 0;
	Q.rear = 0;
	return true;
}
//清空队列
int ClearQueue(SqQueue& Q)
{
	Q.front = Q.rear;
	return true;
}
//舞伴问题
void DancePartner(SqQueue& Mdancers, SqQueue& Fdancers, Person dancer[], int num)
{
	InitQueue(Mdancers);
	InitQueue(Fdancers);
	Person F, M;
	for (int i = 0; i < num; i++)
	{
		if (dancer[i].sex == "F") //如果是女性
		{
			if (!IsFull(Fdancers)) //如果没满
				pushQueue(Fdancers, dancer[i]);
		}
		else
		{
			if (!IsFull(Mdancers)) //如果没满
				pushQueue(Mdancers, dancer[i]);
		}
	}
	while (!IsEmpty(Fdancers) && !IsEmpty(Mdancers))
	{
		popQueue(Fdancers, F);
		cout << F.name << " ";
		popQueue(Mdancers, M);
		cout << M.name << " ";
	}
	if (!IsEmpty(Fdancers))
	{
		GetHead(Fdancers, F);
		cout << "The first woman to get a partner is:" << F.name << endl;
	}
	if (!IsEmpty(Mdancers))
	{
		GetHead(Mdancers, M);
		cout << "The first man to get a partner is:" << M.name << endl;
	}
}