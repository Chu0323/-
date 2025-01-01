#include "Linear_queue.h"
#include <cstdlib>
//��ʼ��ѭ������
void InitQueue(SqQueue& Q)
{
	Q.base = new QElemType[MAXQSIZE];
	if (!Q.base)
		exit(OVERFLOW); //������ֹ����ִ�У������ز����������ϵͳ
	//����0����ʾ�����˳���
	Q.front = 0;
	Q.rear = Q.front;
}
//��ȡѭ�����еĳ���
int QueueLength(SqQueue& Q)
{
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
//�ж�ѭ�������Ƿ�Ϊ��
int IsEmpty(SqQueue& Q)
{
	if (Q.front == Q.rear)
		return true;
	return false;
}
//ѭ���������
int pushQueue(SqQueue& Q, QElemType e)
{
	if (IsEmpty(Q) || ((Q.rear + 1) % MAXQSIZE == Q.front)) //�ӿա�����
		return false;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE; //ѭ������
	return true;
}
//ѭ�����г���
int popQueue(SqQueue& Q, QElemType& e)
{
	if (IsEmpty(Q) || ((Q.rear + 1) % MAXQSIZE == Q.front))
		return false;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE; //ѭ������
	return true;
}
//ȡ��ͷԪ��
int GetHead(SqQueue& Q, QElemType& e)
{
	if (IsEmpty(Q))
		return false;
	e = Q.base[Q.front];
	return true;
}