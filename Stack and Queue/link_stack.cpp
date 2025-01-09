#include <iostream>
#include "link_stack.h"
using namespace std;

//����ͷ��㣬��ջ��ʼ��
void InitStack(LinkStack& s)
{
	s = NULL;
}
//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(LinkStack& s)
{
	if (!s)
		return true;
	return false;
}
//������ջ
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
//��ջ
//�Ƚ������
int PushStack(LinkStack& s, SElemType e)
{
	SNode* p = new SNode;
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
//��������һ���Ǹ���ʮ����������ӡ��������ֵ�İ˽�����
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
