#pragma once
#ifndef _SEQUENTIAL_STACK_H
#define _SEQUENTIAL_STACK_H

#define MAXSIZE 6
#define SElemType char

typedef struct Stack
{
	SElemType* base; //栈底指针
	SElemType* top; //栈顶指针
	int stacksize; //栈可用最大容量
}Sqstack;

int InitStack(Sqstack& s);
int DestoryStack(Sqstack& s);
int StackEmpty(Sqstack& s);
int StackLength(Sqstack& s);
int ClearStack(Sqstack& s);
int PushStack(Sqstack& s, SElemType e);
int PopStack(Sqstack& s, SElemType& e);
int GetTop(Sqstack& s, SElemType& e);
SElemType EvaluateExpression(Sqstack& OPTR, Sqstack& OPND);

#endif


