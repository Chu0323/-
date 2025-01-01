#include "link_queue.h"
//链队初始化
int InitLinkQueue(LinkQueue& Q)
{
	Q.front = (Queue)new QNode;
	if (!Q.front)
		return false;
	Q.front->next = NULL;
	Q.rear = Q.front;
	return true;
}
//判断链队列是否为空
int IsEmpty(LinkQueue& Q)
{
	if (Q.rear == Q.front)
		return true;
	return false;
}
//销毁链队列（有头结点）
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
//链队-入队
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
//链队-出队(有头结点）
int PopLinkQueue(LinkQueue& Q, QElemType& e)
{
	
	if (IsEmpty(Q))
		return false;
	QNode* p;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) //如果被删的元素刚好是最后一个元素
		Q.rear = Q.front;
	delete p;
	return true;
}
//链队-获取头元素
int GetHead(LinkQueue& Q, QElemType& e)
{
	if (IsEmpty(Q))
		return false;
	e = Q.front->next->data;
	return true;
}