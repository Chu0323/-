#include "link_stack.h"
//链栈初始化,不含头节点
void InitStack(LinkStack& s)
{
	s = NULL;
}
//判断链栈是否为空
int StackEmpty(LinkStack& s)
{
	if (!s)
		return true;
	return false;
}
//入栈
int PushStack(LinkStack& s, SElemType e)
{
	StackNode* p = (StackNode*)new StackNode;
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
	e = s->data;
	StackNode* p = s;
	s = s->next;
	delete p;
	return true;
}
//取栈顶元素
int GetTop(LinkStack& s, SElemType& e)
{
	if (StackEmpty(s))
		return false;
	e = s->data;
	return true;
}
