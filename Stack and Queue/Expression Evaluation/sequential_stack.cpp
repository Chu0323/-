#include "sequential_stack.h"
#include <cstdlib>

int InitStack(Sqstack& s)
{
	s.base = new SElemType[MAXSIZE];
	if (!s.base)
		exit(OVERFLOW); //立即终止程序运行，并返回操作码给系统
		//返回0，表示正常退出
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
