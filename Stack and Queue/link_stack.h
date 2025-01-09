#pragma once
#ifndef _LINK_STACK_H
#define _LINK_STACK_H

#define SElemType int

typedef struct SNode
{
	SElemType data;
	struct SNode* next;
} SNode, *LinkStack;

void InitStack(LinkStack& s);
int StackEmpty(LinkStack& s);
int DeleteStack(LinkStack& s);
int PushStack(LinkStack& s, SElemType e);
int PopStack(LinkStack& s, SElemType& e);
int GetTop(LinkStack& s, SElemType& e);
void conversion(LinkStack& s, int N);




#endif
