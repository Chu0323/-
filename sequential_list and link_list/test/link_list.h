#ifndef _LINK_LIST
#define _LINK_LIST

#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define ElemType data
#define Status int

typedef struct 
{
	int *p; //系数
	int *e; //指数
}data;

typedef struct Lnode
{
	ElemType data;
	struct Lnode* next;
}Lnode, *LinkList; //LinkList是一种指向结构体Lnode的指针

//双向链表
typedef struct DuLnode
{
	ElemType data;
	struct DuLnode *prior, *next;
}DuLnode, *DuLinkList; //DuLinkList是一种指向结构体Lnode的指针

typedef struct
{
	float coef; //系数
	int expn; //指数
	struct Pnode *next;
}Pnode, *Polymial; //用链表表示的多项式

Status InitList(LinkList L);
int IsEmpty(LinkList L);
void DestoryList(LinkList L);
int ClearList(LinkList L);
int ListLength(LinkList L);
int GetElem(LinkList L, int i, ElemType e);
int LocateElem(LinkList L, ElemType e);
int InsertList(LinkList L, int i, ElemType e);
int DeleteList(LinkList L, int i, ElemType e);
void CreateList_H(LinkList L, int n);
void CreateList_L(LinkList L, int n);
LinkList Connect(LinkList Ta, LinkList Tb);
void ListInsert_Dul(DuLinkList L, int i, ElemType e);
int ListDelete_Dul(DuLinkList L, int i, ElemType e);

#endif
