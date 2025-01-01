#pragma once
#ifndef _SEQUENTIAL_STACK_H
#define _SEQUENTIAL_STACK_H

#define MAXSIZE 100
#define OVERFLOW -2
#define SElemType int
#include <iostream>
typedef struct Stack
{
	SElemType* base; //栈底指针
	SElemType* top; //栈顶指针
	int stacksize; //栈可用最大容量
}Sqstack;
void InitStack(Sqstack& s);
int DestoryStack(Sqstack& s);
int StackEmpty(Sqstack& s);
int StackLength(Sqstack& s);
int ClearStack(Sqstack& s);
int PushStack(Sqstack& s, SElemType e);
int PopStack(Sqstack& s, SElemType& e);


#endif




