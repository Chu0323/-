#pragma once
#ifndef _MYSTRING_H
#define _MYSTRING_H

#define MAXLEN 255

typedef struct
{
	char len[MAXLEN + 1]; //�洢����һά����
	int length; //���ĵ�ǰ����
} SString;

//StrAssign(&T, chars) //����ֵ
//StrCompare(S, T) //���Ƚ�
//StrLength(s) //�󴮳�
//Concat(&T, s1, s2) //������
//Substring(&Sub, S, pos, len) //���Ӵ�
//StrCopy(S) //������
//StrEmpty(S) //���п�
//ClearString(S) ����ַ���
//Index(S, T, pos) //�Ӵ���λ��
//Replace(S, T, V) //���滻
//StrInsert(S, pos, T) //�Ӵ�����
//StrDelete(S, pos, len) //�Ӵ�ɾ��
//DestoryString(S) //������
/*
����ģʽƥ���㷨��
	�㷨Ŀ�ģ�ȷ�������������Ӵ�(ģʽ��)��һ�γ��ֵ�λ��(��λ��
	�㷨Ӧ�ã��������桢ƴд��顢���Է��롢����ѹ��
	�㷨���ࣺ
		BF�㷨(Brute-Force,�����ƽⷨ)
		KMP�㷨(�ص�:�ٶȿ�)
*/
//BF�㷨
int Index(SString& S, SString& T);
//KMP�㷨
int index_KMP(SString& S, SString& T, int* next);

#endif







