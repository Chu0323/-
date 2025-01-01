#include "link_queue.h"
//���ӳ�ʼ��
int InitLinkQueue(LinkQueue& Q)
{
	Q.front = (Queue)new QNode;
	if (!Q.front)
		return false;
	Q.front->next = NULL;
	Q.rear = Q.front;
	return true;
}
//�ж��������Ƿ�Ϊ��
int IsEmpty(LinkQueue& Q)
{
	if (Q.rear == Q.front)
		return true;
	return false;
}
//���������У���ͷ��㣩
int DeleteLinkQueue(LinkQueue& Q)
{
	QNode* p;
	while (Q.front)
	{
		p = Q.front;
		Q.front = p->next;
		delete p;
	}
	return true;
}
//����-���
int PushLinkQueue(LinkQueue& Q, QElemType& e)
{
	QNode* p = new QNode;
	if (!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = Q.rear->next;
	Q.rear->next = p;
	Q.rear = p;
	return true;
}
//����-����(��ͷ��㣩
int PopLinkQueue(LinkQueue& Q, QElemType& e)
{
	
	if (IsEmpty(Q))
		return false;
	QNode* p;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) //�����ɾ��Ԫ�ظպ������һ��Ԫ��
		Q.rear = Q.front;
	delete p;
	return true;
}
//����-��ȡͷԪ��
int GetHead(LinkQueue& Q, QElemType& e)
{
	if (IsEmpty(Q))
		return false;
	e = Q.front->next->data;
	return true;
}