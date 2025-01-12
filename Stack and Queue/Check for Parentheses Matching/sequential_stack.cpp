#include "sequential_stack.h"
#include <cstdlib>
#include <iostream>
using namespace std;

int InitStack(Sqstack& s)
{
	s.base = new SElemType[MAXSIZE];
	if (!s.base)
		exit(OVERFLOW); //������ֹ�������У������ز������ϵͳ
		//����0����ʾ�����˳�
	s.top = s.base;
	s.stacksize = MAXSIZE;
	return true;
}
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
int StackEmpty(Sqstack& s)
{
	if (s.base == s.top)
		return true;
	return false;
}
int StackLength(Sqstack& s)
{
	return s.top - s.base;
}
int ClearStack(Sqstack& s)
{
	if (s.base)
		s.top = s.base;
	return true;
}
int PushStack(Sqstack& s, SElemType e)
{
	if (s.top - s.base == MAXSIZE)
		return false; 
	*(s.top++) = e;
	return true;
}
int PopStack(Sqstack& s, SElemType& e)
{
	if (StackEmpty(s))
		return false;
	e = *(--s.top);
	return true;
}
int GetTop(Sqstack& s, SElemType& e)
{
	if (StackEmpty(s))
		return false;
	e = *(--s.top);
	s.top++;
	return true;
}
//�����ʽ�����������Ƿ���ȷƥ�䡣���ƥ�䣬�򷵻�true�����򷵻�false
int Matching(Sqstack& s)
{
	SElemType e;
	char ch;
	int flag = 1;
	InitStack(s);
	cin >> ch;
	while (ch != '#' && flag) //������ʽ�ԡ�#����β
	{
		switch (ch)
		{
		case '[' || '(':
			PushStack(s, ch);
			break;
		case ')':
			if (!StackEmpty(s) && GetTop(s, e) == '(')
				PopStack(s, e);
			else
			{
				flag = 0;
				break;
			}
		case ']':
			if (!StackEmpty(s) && GetTop(s, e) == '(')
				PopStack(s, e);
			else
			{
				flag = 0;
				break;
			}
		}
		cin >> ch;
	}
	if (StackEmpty(s) && flag)
		return true;
	return false;
}
//�ж������ַ������ȼ�
char Precede(char ch1, char ch2)
{
	//������������ȼ���
	int PrecedeTable[7][7] =
	{
		{1, 1, 0, 0, 0, 1, 1},
		{1, 1, 0, 0, 0, 1, 1},
		{1, 1, 1, 1, 0, 1, 1},
		{1, 1, 1, 1, 0, 1, 1},
		{0, 0, 0, 0, 0, 2, -1},
		{1, 1, 1, 1, -1, 1, 1},
		{0, 0, 0, 0, 0, -1, 2},
	};
	int row = 0, column = 0;
	switch (ch1)
	{ 
	case '+': row = 0; break;
	case '-': row = 1; break;
	case '*': row = 2; break;
	case '/': row = 3; break;
	case '(': row = 4; break;
	case ')': row = 5; break;
	case '#': row = 6; break;
	}
	switch (ch2)
	{
	case '+': column = 0; break;
	case '-': column = 1; break;
	case '*': column = 2; break;
	case '/': column = 3; break;
	case '(': column = 4; break;
	case ')': column = 5; break;
	case '#': column = 6; break;
	}
	if (PrecedeTable[row][column] == 0)
		return '<';
	else if (PrecedeTable[row][column] == 1)
		return '>';
	else if (PrecedeTable[row][column] == 2)
		return '=';
	else if (PrecedeTable[row][column] == -1)
	{
		exit(ERROR);
		return '0';
	}	
}
//�ַ�����
char Operate(char a, char theta, char b)
{
	int m = a - '0';
	int n = b - '0';
	int ret = 0;
	switch (theta)
	{
	case '+': ret = m + n; break;
	case '-': ret = m - n; break;
	case '*': ret = m * n; break;
	case '/': ret = m / n; break;
	}
	return (char)(ret + '0');
}
//�������ʽ��ֵ����������㷨����OPTR��OPND�ֱ�Ϊ�����ջ�Ͳ�����ջ
SElemType EvaluateExpression(Sqstack& OPTR, Sqstack& OPND)
{
	char ch;
	SElemType e, theta, a, b;
	InitStack(OPTR); //�����ջ
	InitStack(OPND); //������ջ
	PushStack(OPTR, '#');
	cin >> ch;
	GetTop(OPND, e);
	while (ch != '#' || e != '#')
	{
		if (isdigit(ch)) // ���ch����0~9���򷵻ط���ֵ
		{
			PushStack(OPND, ch); cin >> ch;
		}
		else
		{
			GetTop(OPTR, e);
			switch (Precede(e, ch))
			{
			case '<':
				PushStack(OPTR, ch); cin >> ch;
				break;
			case '>':
					PopStack(OPTR, theta);
					PopStack(OPND, b);
					PopStack(OPND, a);
					PushStack(OPND, Operate(a, theta, b));
					break;
			case '=':
				PopStack(OPTR, e);
				break;
			}
		}
	}
	GetTop(OPND, e);
	return e;
}
