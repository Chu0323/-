#pragma once
#ifndef _SEQUENTIAL_STACK_H
#define _SEQUENTIAL_STACK_H

#define MAXSIZE 100
#define OVERFLOW -2
#define SElemType int
#include <iostream>
typedef struct Stack
{
	SElemType* base; //ջ��ָ��
	SElemType* top; //ջ��ָ��
	int stacksize; //ջ�����������
}Sqstack;
void InitStack(Sqstack& s);
int DestoryStack(Sqstack& s);
int StackEmpty(Sqstack& s);
int StackLength(Sqstack& s);
int ClearStack(Sqstack& s);
int PushStack(Sqstack& s, SElemType e);
int PopStack(Sqstack& s, SElemType& e);


#endif




