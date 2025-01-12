#include <iostream>
#include <fstream>
#include <cstring>
#include "mystring.h"
using namespace std;

int Index(SString& S, SString& T)
{
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length) //i的值超过长度说明匹配不成功
	//j的值超过长度说明匹配成功
	{
		if (S.len[i] == T.len[j])
		{
			++i; ++j; //主串和子串依次匹配下一个字符
		}
		else
		{
			i = i - j + 2; j = 1; //主串、子串指针回溯重新开始下一次匹配
		}
	}
	if (j > T.length)
		return i - T.length; //返回匹配的第一个字符的下标
	return 0; //没有匹配成功
}
//定义next[j]函数，
//next[j] = max{k|1<k<j, 从头开始的K-1个元素(前缀） == j前面的K-1个元素(后缀)
//			= 0, j = 1
//			= 1, 其他情况
void get_next(SString& T, int* next)
{
	int i = 1, j = 0;
	next[1] = 0;
	while (i < T.length)
	{
		if (j == 0 || T.len[i] == T.len[j])
		{
			++i; ++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}
int index_KMP(SString& S, SString& T, int* next)
{
	int i = 1, j = 1;
	get_next(T, next);
	while (i <= S.length && j <= T.length) //i的值超过长度说明匹配不成功
		//j的值超过长度说明匹配成功
	{
		if (S.len[i] == T.len[j])
		{
			++i, ++j;
		}
		else
		{
			j = next[j]; /*i不变,j后退*/
		}
	}
	if (j > T.length)
		return i - T.length; //返回匹配的第一个字符的下标
	return 0; //没有匹配成功
}