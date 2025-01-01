#pragma once
#ifndef _LINK_QUEUE_H
#define _LINK_QUEUE_H

#include <iostream>
#define QElemType int
//Á´¶Ó
typedef struct QNode
{
	QElemType data;
	struct QNode* next;
} QNode, *Queue;
typedef struct
{
	Queue front; //¶ÓÍ·Ö¸Õë
	Queue rear; //¶ÓÎ²Ö¸Õë
} LinkQueue;

#endif
