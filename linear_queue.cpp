#include "Linear_queue.h"
#include <cstdlib>
//初始化循环队列
void InitQueue(SqQueue& Q)
{
	Q.base = new QElemType[MAXQSIZE];
	if (!Q.base)
		exit(OVERFLOW); //立即终止程序执行，并返回操作码给操作系统
	//返回0，表示正常退出；
	Q.front = 0;
	Q.rear = Q.front;
}
//获取循环队列的长度
int QueueLength(SqQueue& Q)
{
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
//判断循环队列是否为空
int IsEmpty(SqQueue& Q)
{
	if (Q.front == Q.rear)
		return true;
	return false;
}
//循环队列入队
int pushQueue(SqQueue& Q, QElemType e)
{
	if (IsEmpty(Q) || ((Q.rear + 1) % MAXQSIZE == Q.front)) //队空、队满
		return false;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE; //循环队列
	return true;
}
//循环队列出队
int popQueue(SqQueue& Q, QElemType& e)
{
	if (IsEmpty(Q) || ((Q.rear + 1) % MAXQSIZE == Q.front))
		return false;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE; //循环队列
	return true;
}
//取队头元素
int GetHead(SqQueue& Q, QElemType& e)
{
	if (IsEmpty(Q))
		return false;
	e = Q.base[Q.front];
	return true;
}