#include <iostream>
#include <fstream>
#include <cstring>
#include "mystring.h"
using namespace std;

int Index(SString& S, SString& T)
{
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length) //i��ֵ��������˵��ƥ�䲻�ɹ�
	//j��ֵ��������˵��ƥ��ɹ�
	{
		if (S.len[i] == T.len[j])
		{
			++i; ++j; //�������Ӵ�����ƥ����һ���ַ�
		}
		else
		{
			i = i - j + 2; j = 1; //�������Ӵ�ָ��������¿�ʼ��һ��ƥ��
		}
	}
	if (j > T.length)
		return i - T.length; //����ƥ��ĵ�һ���ַ����±�
	return 0; //û��ƥ��ɹ�
}
//����next[j]������
//next[j] = max{k|1<k<j, ��ͷ��ʼ��K-1��Ԫ��(ǰ׺�� == jǰ���K-1��Ԫ��(��׺)
//			= 0, j = 1
//			= 1, �������
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
	while (i <= S.length && j <= T.length) //i��ֵ��������˵��ƥ�䲻�ɹ�
		//j��ֵ��������˵��ƥ��ɹ�
	{
		if (S.len[i] == T.len[j])
		{
			++i, ++j;
		}
		else
		{
			j = next[j]; /*i����,j����*/
		}
	}
	if (j > T.length)
		return i - T.length; //����ƥ��ĵ�һ���ַ����±�
	return 0; //û��ƥ��ɹ�
}