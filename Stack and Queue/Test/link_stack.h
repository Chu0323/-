#pragma once
#ifndef _LINK_STACK_H
#define _LINK_STACK_H
#include <iostream>

#define SElemType int
typedef struct StackNode
{
	SElemType data;
	struct StackNode* next;
} StackNode, *LinkStack;

void InitStack(LinkStack& s);
int StackEmpty(LinkStack& s);


#endif

