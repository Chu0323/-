#pragma once
#ifndef _SEQUENTIAL_STACK_H
#define _SEQUENTIAL_STACK_H

#define MAXSIZE 6
#define SElemType char

typedef struct Stack
{
	SElemType* base; //ջ��ָ��
	SElemType* top; //ջ��ָ��
	int stacksize; //ջ�����������
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


