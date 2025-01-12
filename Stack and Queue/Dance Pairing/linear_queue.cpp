#include <iostream>
#include <cstdlib>
#include "linear_queue.h"
using namespace std;
//���Զ��г�ʼ��
void InitQueue(SqQueue& Q)
{
	Q.base = new Person[MAXSIZE];
	if (!Q.base)
		exit(OVERFLOW);
	Q.front = 0;
	Q.rear = Q.front;
}
//���ض��еĳ���
int QueueLength(SqQueue& Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}
//�ж϶����Ƿ�Ϊ��
int IsEmpty(SqQueue& Q)
{
	if (Q.front == Q.rear)
		return true;
	return false;
}
//�ж϶����Ƿ�����
int IsFull(SqQueue& Q)
{
	if ((Q.rear + 1) % MAXSIZE == Q.front)
		return true;
	return false;
}
//���
int pushQueue(SqQueue& Q, Person& e)
{
	if ((Q.rear + 1) % MAXSIZE == Q.front) //����
		return false;
	Q.base[Q.rear].name = e.name;
	Q.base[Q.rear].sex = e.sex;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return true;
}
//����
int popQueue(SqQueue& Q, Person& e)
{
	if (IsEmpty(Q))
		return false;
	e.name = Q.base[Q.front].name;
	e.sex = Q.base[Q.front].sex;
	Q.front = (Q.front + 1) % MAXSIZE;
	return true;
}
//��ȡͷԪ��
int GetHead(SqQueue& Q, Person& e)
{
	if (IsEmpty(Q))
		return false;
	e = Q.base[Q.front];
	return true;
}
//���ٶ���
int DeleteQueue(SqQueue& Q)
{
	delete[] Q.base;
	Q.base = NULL;
	Q.front = 0;
	Q.rear = 0;
	return true;
}
//��ն���
int ClearQueue(SqQueue& Q)
{
	Q.front = Q.rear;
	return true;
}
//�������
void DancePartner(SqQueue& Mdancers, SqQueue& Fdancers, Person dancer[], int num)
{
	InitQueue(Mdancers);
	InitQueue(Fdancers);
	Person F, M;
	for (int i = 0; i < num; i++)
	{
		if (dancer[i].sex == "F") //�����Ů��
		{
			if (!IsFull(Fdancers)) //���û��
				pushQueue(Fdancers, dancer[i]);
		}
		else
		{
			if (!IsFull(Mdancers)) //���û��
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