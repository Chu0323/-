#include <iostream>
#include "link_stack.h"
using namespace std;

//不含头结点，链栈初始化
void InitStack(LinkStack& s)
{
	s = NULL;
}
//判断栈是否为空
int StackEmpty(LinkStack& s)
{
	if (!s)
		return true;
	return false;
}
//销毁链栈
int DeleteStack(LinkStack& s)
{
	while (s)
	{
		SNode* p = s;
		s = p->next;
		delete p;
	}
	return true;
}
//入栈
//先进后出，
int PushStack(LinkStack& s, SElemType e)
{
	SNode* p = new SNode;
	p->data = e;
	p->next = s;
	s = p;
	return true;
}
//出栈
int PopStack(LinkStack& s, SElemType& e)
{
	if (StackEmpty(s))
		return false;
	SNode* p = s;
	s = p->next;
	e = p->data;
	delete p;
	return true;
}
int GetTop(LinkStack& s, SElemType& e)
{
	if (StackEmpty(s))
		return false;
	e = s->data;
	return true;
}
//对于任意一个非负的十进制数，打印输出与其等值的八进制数
void conversion(LinkStack& s, int N)
{
	SElemType e;
	InitStack(s);
	while (N)
	{
		PushStack(s, N % 8);
		N /= 8;
	}
	while (!StackEmpty(s))
	{
		PopStack(s, e);
		cout << e;
	}
}
