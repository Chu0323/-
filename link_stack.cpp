#include "link_stack.h"
//Á´Õ»³õÊ¼»¯,²»º¬Í·½Úµã
void InitStack(LinkStack& s)
{
	s = NULL;
}
//ÅĞ¶ÏÁ´Õ»ÊÇ·ñÎª¿Õ
int StackEmpty(LinkStack& s)
{
	if (!s)
		return true;
	return false;
}
//ÈëÕ»
int PushStack(LinkStack& s, SElemType e)
{
	StackNode* p = (StackNode*)new StackNode;
	p->data = e;
	p->next = s;
	s = p;
	return true;
}
//³öÕ»
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
//È¡Õ»¶¥ÔªËØ
int GetTop(LinkStack& s, SElemType& e)
{
	if (StackEmpty(s))
		return false;
	e = s->data;
	return true;
}