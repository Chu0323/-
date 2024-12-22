#include <stdio.h>
#include <stdlib.h>
#include "sequence_list.h"

//Initialize the linear table
Status InitList(SqList* L) 
{
	L->elem = (ElemType*)malloc(sizeof(ElemType*)*MAX_SIZE); //为顺序表分配空间
	//malloc 用于在堆区中分配一块连续的内存空间，并返回这段空间的首地址
	//如果赋值失败(内存不足),L->elem = NULL;
	if (!L->elem)
	{
		exit(OVERFLOW); 
		//存储分配失败,返回状态码给系统,0表示成功执行,非零值表示出现异常
		L->length = 0;
	}
	return OK;
};
//初始条件：线性表L已存在 操作结果：销毁线性表L
void DestroyList(SqList* L) 
{
	if (L->elem)
	{
		free(L->elem);	//释放指针elem所指变量的存储空间
		//为了避免意外地访问已经释放的内存，释放后最好将指针赋值为NULL，即p = NULL;。
		L->elem = NULL;
    }
}
//初始条件：线性表L已存在 操作结果：将线性表L重置为空表
void ClearList(SqList* L) 
{
	L->length = 0;
}
//初始条件：线性表L已存在 操作结果：返回线性表L中的数据元素个数
int GetListLength(SqList* L) 
{
	return L->length;
};
//初始条件：线性表L已存在 操作结果：若L为空表，则返回true,否则返回false
int IsEmpty(SqList* L) 
{
	if (L->length == 0)
		return TRUE;
	else
		return FALSE;
};
//初始条件：线性表L已存在 操作结果：用e返回线性表L中第i个数据元素的值
int GetElem(SqList* L, int i, ElemType e) 
{
	if (i < 1 || i > L->length);
		return ERROR;
	e = L->elem[i - 1]; //elem是指针，而elem[i-1]则是指针指向的元素
	return OK;
};
 //初始条件：线性表L已存在 操作结果：用e返回线性表L中该元素的位置
int LocateElem(SqList* L, ElemType e)
{
	for (int i = 0; i < L->length; ++i)
	{
		if (L->elem[i].p == e.p && L->elem[i].e == e.e)
			return i + 1;
	}
	return ERROR;
}
//初始条件：线性表L已存在  操作结果：返回当前元素的前驱
int PriorElem(SqList* L, ElemType cur_e, ElemType pre_e)
{
	int location = LocateElem(L, cur_e);
	if (location == 0)
		return ERROR; 
	else if (location == 1)
		return ERROR;
	else
	{
		pre_e = L->elem[location - 2];
		return OK;
	}
}
//初始条件：线性表L已存在， 操作结果：返回当前元素的后继
int NextElem(SqList* L, ElemType cur_e, ElemType next_e)
{
	int location = LocateElem(L, cur_e);
	if (location == 0)
		return ERROR; 
	else if (location == L->length)
		return ERROR;
	else
	{
		next_e = L->elem[location];
		return OK;
	}
}
//在线性表中第i个位置上插入元素e
int ListInsert(SqList* L, int i, ElemType e)
{
	if (i < 1 || i > L->length + 1)
		return ERROR;
	else if (L->length == MAX_SIZE)
		return ERROR;
	else
	{
		for (int j = L->length; j > i - 1; --j)
		{
			L->elem[j] = L->elem[j - 1];
		}
		L->elem[i] = e;
		++L->length;
		return OK;
	}	
}
//删除线性表中第i个元素
int ListDelete(SqList* L, int i)
{
	if (i < 1 || i > L->length)
		return ERROR;
	else
	{
		for (int j = i - 1; j < L->length - 1; ++j)
		{
			L->elem[j] = L->elem[j+1];
		}
		--L->length;
		return OK;
	}
}
//线性表的合并
void Union(SqList *La, SqList *Lb)
{
	int lb_len = GetListLength(Lb);
	int la_len = GetListLength(La);
	ElemType e;
	for (i = 0; i < lb_len; ++i) 
	{
		GetElem(Lb, i+1, e); //遍历Lb中的每个元素
		if (!LocateElem(La, e)) //如果e不在La中
			ListInsert(La, ++la_len, e);	 
	}
}
//有序表的合并
/*已知线性表La和Lb的数据元素按值非递减有序排列
现要求将La和Lb归并为一个新的线性表Lc,且Lc中的数据元素仍按值非递减有序排列*/
void Sequential_Union(SqList *La, SqList *Lb, SqList *Lc)
{
	ElemType *pa, *pb, *pc, *pa_last, *pb_last;
	pa = La->elem;
	pb = Lb->elem; //指针pa和pb分别指向两个表的第一个元素
	Lc->length = La->length + Lb->length; //新表长度先假设为两表的长度之和
	L->elem = (ElemType*)malloc(sizeof(ElemType*)*Lc.length); //为顺序表分配空间
	
	Lc->length = 0;
	pc = Lc->elem;
	pa_last = La->elem + La.length - 1;
	pb_last = Lb->elem + Lb.length - 1;
	while (pa <= pa_last && pb <= pb_last)
	{
		if (*pa <= *pb) //依次摘取两个表中值较小的结点
			*pc = *pa++;
		else
			*pc = *pb++;
		pc++;
		Lc->length += 1;
	}
	while (pa <= pa_last) //pb已到达表尾，将La中剩余元素加入Lc
	{
		*pc = *pa++; //后缀自增运算符的优先级高于*,因此，先执行pa++
		//后缀自增先返回pa的值,也即*pc = *pa;在进行pa++
		pc++;
		Lc->length += 1;
	}
	while (pb <= pb_last)
	{
		*pc = *pb++;
		pc++;
		Lc->length += 1;
	}
}
		
		
		
		