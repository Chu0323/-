#pragma once
#ifndef _LINK_QUEUE_H
#define _LINK_QUEUE_H

#include <iostream>
#define QElemType int
//链队
typedef struct QNode
{
	QElemType data;
	struct QNode* next;
} QNode, *Queue;
typedef struct
{
	Queue front; //队头指针
	Queue rear; //队尾指针
} LinkQueue;

#endif
