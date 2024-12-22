#ifndef _SEQUENCE_LIST
#define _SEQUENCE_LIST

#define MAX_SIZE 100 //线性表存储空间的初始分配量

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef struct //多项式非零项的定义
{
	int* p; //系数
	int* e; //指数
} Polynomial;

typedef int Status; //函数结果状态代码
typedef Polynomial ElemType;

//线性表
typedef struct
{
	ElemType* elem; //数组动态分配
	int length;
} SqList;
//typedef struct
//{
//	ElemType elem[LIST_INIT_SIZE]; //数组静态分配
//	int length;
//} SqList;

Status InitList(SqList* L); 
void DestroyList(SqList* L); 
void ClearList(SqList* L); 
int GetListLength(SqList* L); 
int IsEmpty(SqList* L); 
int GetElem(SqList* L, int i, ElemType e); 
int LocateElem(SqList* L, ElemType e);
int PriorElem(SqList* L, ElemType cur_e, ElemType pre_e);
int NextElem(SqList* L, ElemType cur_e, ElemType next_e);
int ListInsert(SqList* L, int i, ElemType e);
int ListDelete(SqList* L, int i);
void Union(SqList *La, SqList *Lb);
void Sequential_Union(SqList *La, SqList *Lb, SqList *Lc);

#endif
