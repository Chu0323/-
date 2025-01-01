#include "link_stack.h"
//��ջ��ʼ��,����ͷ�ڵ�
void InitStack(LinkStack& s)
{
	s = NULL;
}
//�ж���ջ�Ƿ�Ϊ��
int StackEmpty(LinkStack& s)
{
	if (!s)
		return true;
	return false;
}
//��ջ
int PushStack(LinkStack& s, SElemType e)
{
	StackNode* p = (StackNode*)new StackNode;
	p->data = e;
	p->next = s;
	s = p;
	return true;
}
//��ջ
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
//ȡջ��Ԫ��
int GetTop(LinkStack& s, SElemType& e)
{
	if (StackEmpty(s))
		return false;
	e = s->data;
	return true;
}