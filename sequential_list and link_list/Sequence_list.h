#pragma once
#ifndef _SEQUENCE_LIST
#define _SEQUENCE_LIST
#include <cstring>
using namespace std;

#define MAX_SIZE 100 //线性表存储空间的初始分配量
#define ERROR -1
typedef int Status; //函数结果状态代码

struct Book
{
	char id[20]; //ISBN
	char name[50]; //书名 //最初的时候，我用的是string类型，但是报错，
	int price; //定价
};
typedef struct //顺序表
{
	Book* elem;
	int length;
} Sqlist;

Status InitList(Sqlist* L);
void DestroyList(Sqlist* L);
void ClearList(Sqlist* L);
int GetListLength(Sqlist* L);
int IsEmpty(Sqlist* L);
int GetElem(Sqlist* L, int i, Book& e);
int LocateElem(Sqlist* L, Book e);
int PriorElem(Sqlist* L, Book cur_e, Book& pre_e);
int NextElem(Sqlist* L, Book cur_e, Book& next_e);
int ListInsert(Sqlist* L, int i, Book e);
int ListDelete(Sqlist* L, int i);
void Union(Sqlist* La, Sqlist* Lb);
void Sequential_Union(Sqlist* La, Sqlist* Lb, Sqlist* Lc);
void PrintList(Sqlist* L);
void PrintInfo(Book e);

#endif
