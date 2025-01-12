#pragma once
#ifndef _MYSTRING_H
#define _MYSTRING_H

#define MAXLEN 255

typedef struct
{
	char len[MAXLEN + 1]; //存储串的一维数组
	int length; //串的当前长度
} SString;

//StrAssign(&T, chars) //串赋值
//StrCompare(S, T) //串比较
//StrLength(s) //求串长
//Concat(&T, s1, s2) //串连结
//Substring(&Sub, S, pos, len) //求子串
//StrCopy(S) //串拷贝
//StrEmpty(S) //串判空
//ClearString(S) 清空字符串
//Index(S, T, pos) //子串的位置
//Replace(S, T, V) //串替换
//StrInsert(S, pos, T) //子串插入
//StrDelete(S, pos, len) //子串删除
//DestoryString(S) //串销毁
/*
串的模式匹配算法：
	算法目的：确定主串中所含子串(模式串)第一次出现的位置(定位）
	算法应用：搜索引擎、拼写检查、语言翻译、数据压缩
	算法种类：
		BF算法(Brute-Force,暴力破解法)
		KMP算法(特点:速度快)
*/
//BF算法
int Index(SString& S, SString& T);
//KMP算法
int index_KMP(SString& S, SString& T, int* next);

#endif







