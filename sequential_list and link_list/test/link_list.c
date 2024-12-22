#include <stdio.h>
#include <stdlib.h>
#include "link_list.h"

//单链表的初始化(带头结点)
Status InitList(LinkList L)
{
	L = (LinkList)malloc(sizeof(Lnode));
	L->next = NULL;
	return OK;
}
//判断链表是否为空
int IsEmpty(LinkList L)
{
	if (L->next)
		return FALSE;
	return TRUE;
}
//单链表的销毁
void DestoryList(LinkList L)
{
	Lnode* p;
	while (L) //L != NULL
	{
		p = L; //让p指向头结点
		L = L->next;
		free(p);
	}
}
//清空单链表(头指针和头结点还在)
int ClearList(LinkList L)
{
	Lnode *p, *q;
	p = L->next;
	while (p) //p != NULL
	{
		q = p->next;
		free(p);
		p = q;
	}
	if (L->next) //如果首元节点不为空
		return FALSE;
	return TRUE;
}
//求链表表长,返回L中元素个数
int ListLength(LinkList L)
{
	Lnode* p;
	int i = 0;
	p = L->next;
	while (p)
	{
		++i;
		p = p->next;
	}
	return i;
}
//取值,取单链表中第i个元素
int GetElem(LinkList L, int i, ElemType e)
{
	Lnode *p;
	int j = 1;
	p = L->next;
	while (p && j < i) //直到p指向第i个元素或p为空
	{
		p = p->next;
		++j;	
	}
	if (!p || j > i)
		return ERROR;
	e = p->data;
	return OK;
}
//查找
//按值查找: 根据指定数据获取该元素所在的位置(该数据的地址)
//int LocateElem(LinkList L, ElemType e, Lnode* pos)
//{
//	Lnode *p;
//	p = L->next;
//	while (p && p->data != e)
//	{
//		p = p->next;	
//	}
//	if (!p)
//		return ERROR;
//	else
//	{
//		pos = p;
//		return OK;
//	}	
//}
//按值查找: 根据指定数据获取该元素所在的位置序号(是第几号元素)
int LocateElem(LinkList L, ElemType e)
{
	int i = 1;
	Lnode *p;
	p = L->next;
	while (p && p->data != e)
	{
		p = p->next;
		++i;	
	}
	if (!p)
		return ERROR;
	return i;	
}
//插入-在第i个结点前插入值为e的新结点
//如果表是空的，i=1,
int InsertList(LinkList L, int i, ElemType e)
{
	Lnode *p, *q;
	p = (Lnode*)malloc(sizeof(Lnode));
	p->data = e;
	
	int j = 0;
	q = L;
	while (q->next && j < i - 1)
	{
		q = q->next;
		++j;
	}
	if (!q || j > i - 1)
		return ERROR;
	p->next = q->next;
	q->next = p;
	return OK;	
}
//删除-删除第i个结点
int DeleteList(LinkList L, int i, ElemType e)
{
	Lnode *q, *p;
	int j = 0;
	q = L;
	while (q->next && j < i - 1) //找到第i-1个结点
	{
		q = q->next;
		++j;
	}
	if (!q || j > i - 1)
		return ERROR;
	p = q->next; //指向第i个结点
	q->next = p->next;
	e = p->data;
	free(p);
	return OK;
}
//前插法创建单链表
void CreateList_H(LinkList L, int n)
{
	Lnode* p;
	L = (Lnode*)malloc(sizeof(Lnode));
	L->next = NULL;
	for (int i = 0; i < n; ++i)
	{
		p = (Lnode*)malloc(sizeof(Lnode));
		//scanf(&(p->data)); 输入元素值
		p->next = L->next;
		L->next = p;
	}
}
//尾插法建立单链表
void CreateList_L(LinkList L, int n)
{
	Lnode *p, *r;
	L = (Lnode*)malloc(sizeof(Lnode));
	L->next = NULL;
	r = L; //尾指针指向头结点
	for (int i = 0; i < n; ++i)
	{
		p = (Lnode*)malloc(sizeof(Lnode));
		//scanf(&(p->data)); 输入元素值
		p->next = NULL;
		r->next = p;
		r = p;
	}
}
//带尾指针的循环链表的合并
LinkList Connect(LinkList Ta, LinkList Tb)
{
	Lnode *p, *q; //假设Ta,Tb都是非空的单循环链表
	p = Ta->next; //p指向Ta头结点
	q = Tb->next->next; //Tb首元结点
	Ta->next = q;
	free(Tb->next); //释放Tb头结点
	Tb->next = p;
	return Tb->next;
}
//双向链表的插入
int ListInsert_Dul(DuLinkList L, int i, ElemType e)
{
	//在带头结点的双向循环链表L中第i个位置之前插入元素e
	int *p *q;
	p = L;
	int j = 0;
	while (p->next && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR;
	q = (DuLnode)malloc(sizeof(DuLnode));
	q->data = e;
	
	q->prior = p->prior;
	p->prior->next = q;
	p->prior = q;
	q->next = p;
	return OK;
}
//双向链表的删除
int ListDelete_Dul(DuLinkList L, int i, ElemType e)
{
	//删除带头结点的双向循环链表L中第i个位置上的元素，并将其赋给元素e
	int *p *q;
	p = L;
	int j = 0;
	while (p->next && j < i) //p指向第i个元素
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR;
	e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
}

//有序表的合并
/*已知单向不循环链表La和Lb的数据元素按值非递减有序排列
现要求将La和Lb归并为一个新的线性表Lc,且Lc中的数据元素仍按值非递减有序排列*/
void List_Union(LinkList La, LinkList Lb, LinkList Lc)
{
	Lnode *pa, *pb, *pc;
	pa = La->next;
	pb = Lb->next;
	Lc = La;
	pc = Lc;
	while (pa && pb)
	{
		if (pa->data < pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	while (pa) //pa指向的元素不为空
	{
		pc->next = pa;
		pc = pa;
		pa = pa->next;	
	}
	while (pb) //pb指向的元素不为空
	{
		pc->next = pb;
		pc = pb;
		pb = pb->next;	
	}
	free(Lb);
}
//多项式的创建
void CreatePolyn(Polynomial p, int n)
{
	Pnode *pre， *q;
	L = (Polymial)malloc(sizeof(Pnode)); //在堆区创建一个空链表
	L->next = NULL; //首元结点为空
	for (int i = 0; i < n; i++) //输入N个值
	{
		Pnode *p = (Polymial)malloc(sizeof(Pnode)); //生成一个新节点
		scanf("%f", &p->coef);
		scanf("%d", &p->expn); //输入指数和系数
		pre = L; //pre指向头结点
		q = L->next; //q指向首元结点
		
		
		
	}
}





