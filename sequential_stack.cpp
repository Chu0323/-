#include <cstdlib>
#include "sequential_stack.h"
using namespace std;
//顺序栈的初始化
void InitStack(Sqstack& s)
{
	s.base = (SElemType*)new Sqstack[MAXSIZE];
	if (!s.base)
		exit(OVERFLOW); //立即终止程序执行，并返回操作码给操作系统
		//返回0，表示正常退出；
	s.top = s.base;
	s.stacksize = MAXSIZE;
}
//摧毁顺序栈
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
//判断顺序栈是否为空
int StackEmpty(Sqstack& s)
{
	if (s.base == s.top)
		return true;
	return false;
}
//获取顺序栈的长度
int StackLength(Sqstack& s)
{
	return s.top - s.base;
}
//清空数据栈
int ClearStack(Sqstack& s)
{
	if (s.base)
		s.top = s.base;
	return true;
}
int PushStack(Sqstack& s, SElemType e)
{
	if (s.top - s.base == MAXSIZE) //栈满
	{
		cout << "栈满，上溢" << endl;
		return false;
	}
	*s.top++ = e;
	return true;
}
int PopStack(Sqstack& s, SElemType& e)
{
	if (StackEmpty(s)) //栈空
	{
		cout << "栈空，下溢" << endl;
		return false;
	}
	e = *(--s.top);
	return true;
}
