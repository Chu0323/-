#pragma once
#ifndef _SEQUENCE_LIST
#define _SEQUENCE_LIST
#include <cstring>
using namespace std;

#define MAX_SIZE 100 //���Ա�洢�ռ�ĳ�ʼ������
#define ERROR -1
typedef int Status; //�������״̬����

struct Book
{
	char id[20]; //ISBN
	char name[50]; //���� //�����ʱ�����õ���string���ͣ����Ǳ���
	int price; //����
};
typedef struct //˳���
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
