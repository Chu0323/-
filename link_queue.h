#pragma once
#ifndef _LINK_QUEUE_H
#define _LINK_QUEUE_H

#include <iostream>
#define QElemType int
//����
typedef struct QNode
{
	QElemType data;
	struct QNode* next;
} QNode, *Queue;
typedef struct
{
	Queue front; //��ͷָ��
	Queue rear; //��βָ��
} LinkQueue;

#endif
