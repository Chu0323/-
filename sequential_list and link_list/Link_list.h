#pragma once
#ifndef _LINK_LIST_H
#define _LINK_LIST_H
#include <iostream>
#include <cstring>
using namespace std;

#define Status int

struct Book
{
	char id[20]; //ISBN
	char name[50]; //书名
	int price; //定价
};

typedef struct Lnode//链表
{
	int isHead;
	union
	{
		int length;
		Book data;
	};
	struct Lnode* next;
} Lnode, * LinkList;

Status InitList(LinkList& L);
int IsEmpty(LinkList L);
void DestoryList(LinkList& L);
int ClearList(LinkList& L);
int ListLength(LinkList L);
int GetElem(LinkList &L, int i, Book& e);
int LocateElem(LinkList &L, Book e);
int InsertList(LinkList &L, int i, Book e);
int DeleteList(LinkList &L, int i, Book& e);
void CreateList_H(LinkList &L, int n);
void CreateList_L(LinkList &L, int n);

void PrintLinkList(LinkList L);
void PrintElem(Book e);

#endif
