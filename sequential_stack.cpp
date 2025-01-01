#include <cstdlib>
#include "sequential_stack.h"
using namespace std;
//˳��ջ�ĳ�ʼ��
void InitStack(Sqstack& s)
{
	s.base = (SElemType*)new Sqstack[MAXSIZE];
	if (!s.base)
		exit(OVERFLOW); //������ֹ����ִ�У������ز����������ϵͳ
		//����0����ʾ�����˳���
	s.top = s.base;
	s.stacksize = MAXSIZE;
}
//�ݻ�˳��ջ
int DestoryStack(Sqstack& s)
{
	if (s.base)
	{
		delete[] s.base;
		s.stacksize = 0;
		s.top = NULL;
		s.base = s.top;
	}
	return true;
}
//�ж�˳��ջ�Ƿ�Ϊ��
int StackEmpty(Sqstack& s)
{
	if (s.base == s.top)
		return true;
	return false;
}
//��ȡ˳��ջ�ĳ���
int StackLength(Sqstack& s)
{
	return s.top - s.base;
}
//�������ջ
int ClearStack(Sqstack& s)
{
	if (s.base)
		s.top = s.base;
	return true;
}
int PushStack(Sqstack& s, SElemType e)
{
	if (s.top - s.base == MAXSIZE) //ջ��
	{
		cout << "ջ��������" << endl;
		return false;
	}
	*s.top++ = e;
	return true;
}
int PopStack(Sqstack& s, SElemType& e)
{
	if (StackEmpty(s)) //ջ��
	{
		cout << "ջ�գ�����" << endl;
		return false;
	}
	e = *(--s.top);
	return true;
}
