#include <iostream>
#include "Sequence_list.h"
//构造一个空的线性表L
Status InitList(Sqlist *L)
{
	L->length = 0;
	L->elem = (Book*)malloc(sizeof(Book) * MAX_SIZE);
	
	if (!L->elem) //如果赋值失败(内存不足),L->elem = NULL
	{
		exit(OVERFLOW);
		//存储分配失败，返回状态码给系统，非0值表示异常
	}
	return true;
}
//删除线性表
void DestroyList(Sqlist* L)
{
	if (L->elem)
	{
		free(L->elem); //避免重复释放
		L->elem = NULL; //为了避免意外访问释放后的内存,最好还将指针赋值为NULL
	}
	L->length = 0;
}
//清空线性表
void ClearList(Sqlist* L)
{
	L->length = 0;
}
//获取线性表的长度
int GetListLength(Sqlist* L)
{
	return L->length;
}
//判断线性表是否为空
int IsEmpty(Sqlist* L)
{
	if (!L->length)
		return true;
	else
		return false;
}
//获取线性表第i个位置上的元素
int GetElem(Sqlist* L, int i, Book& e)
{
	if (IsEmpty(L)) //如果为空，则返回false
		return false;
	//如果线性表不为空，则检查i是否合法
	if (i < 1 || i > L->length)
		return false;
	e = L->elem[i - 1];
	return true;
}
//重载==运算符
bool operator==(Book &e1, Book &e2)
{
	if (!strcmp(e1.id, e2.id) && !strcmp(e1.name, e2.name) && e1.price == e2.price)
		return true;
	return false;
}
//查询一个元素在线性表处于第几个位置
int LocateElem(Sqlist* L, Book e)
{
	if (IsEmpty(L)) //如果为空，则返回false
		return 0;
	for (int i = 0; i < L->length; i++)
	{
		if (L->elem[i] == e)
			return i + 1;
	}
	return ERROR;
}
//查询一个元素的前驱
int PriorElem(Sqlist* L, Book cur_e, Book& pre_e)
{
	if (IsEmpty(L)) //如果为空或者第一个元素就是cur_e，则返回false
		return false;
	if (L->elem[0] == cur_e)
		return false;
	int ret = LocateElem(L, cur_e);
	pre_e = L->elem[ret - 2];
	return true;
}
//查询一个元素的后继
int NextElem(Sqlist* L, Book cur_e, Book& next_e)
{
	if (IsEmpty(L)) //如果为空或者最后一个元素就是cur_e，则返回false
		return false;
	if (L->elem[L->length - 1] == cur_e)
		return false;
	int ret = LocateElem(L, cur_e);
	next_e = L->elem[ret];
	return true;
}
//在i上插入元素
int ListInsert(Sqlist* L, int i, Book e)
{
	//首先判断i合不合法
	if (i < 1 || i > L->length + 1 || L->length == MAX_SIZE)
		return false;
	for (int j = L->length; j >= i; j--)
	{
		L->elem[j] = L->elem[j - 1];
	}
	L->elem[i - 1] = e;
	L->length += 1;
	return true;
}
//删除第i个位置上的元素
int ListDelete(Sqlist* L, int i)
{
	if (i < 1 || i > L->length)
		return false;
	for (int j = i - 1; j < L->length - 1; j++)
		L->elem[j] = L->elem[j + 1];
	L->length -= 1;
	return true;
}
//顺序表的合并
void Union(Sqlist* La, Sqlist* Lb)
{
	//遍历Lb中元素，如果不在La中，就插入
	int la_len = La->length;
	int lb_len = Lb->length;
	for (int j = 0; j < lb_len; j++)
	{
		int ret = LocateElem(La, Lb->elem[j]);
		if (ret == ERROR)
		{
			ListInsert(La, ++la_len, Lb->elem[j]);
			la_len = La->length; //更新线性表La的长度
		}
	}
}
//char 数组的拷贝
void strcopy(char arr1[], char arr2[])
{
	int len = strlen(arr2);
	for (int i = 0; i < len; i++)
	{
		arr1[i] = arr2[i];
	}
	arr1[len] = '\0';
}

//有序表的合并
/*已知线性表La和Lb的数据元素按price非递减有序排列
现要求将La和Lb归并为一个新的线性表Lc,且Lc中的数据元素仍按值非递减有序排列*/
void Sequential_Union(Sqlist* La, Sqlist* Lb, Sqlist* Lc)
{
	int la_len = La->length;
	int lb_len = Lb->length;
	Book* pa, * pb, * pc, *pa_last, *pb_last;
	pa = La->elem;
	pb = Lb->elem;
	pa_last = La->elem + la_len; //指向的是最后一个元素的下一个位置
	pb_last = Lb->elem + lb_len;
	pc = Lc->elem;
	while (pa != pa_last && pb != pb_last)
	{
		if (pa->price <= pb->price)
		{
			strcopy(pc->id, pa->id);
			strcopy(pc->name, pa->name);
			pc->price = pa->price;
			pa++;
		}	
		else
		{
			strcopy(pc->id, pb->id);
			strcopy(pc->name, pb->name);
			pc->price = pb->price;
			pb++;
		}	
		pc++;
		Lc->length += 1;
	}
	while (pa < pa_last)
	{
		strcopy(pc->id, pa->id);
		strcopy(pc->name, pa->name);
		pc->price = pa->price;
		pa++;
		pc++;
		Lc->length += 1;
	}
	while (pb < pb_last)
	{
		strcopy(pc->id, pb->id);
		strcopy(pc->name, pb->name);
		pc->price = pb->price;
		pb++;
		pc++;
		Lc->length += 1;
	}
}
//打印线性表中的信息
void PrintList(Sqlist* L)
{
	cout << "共有" << L->length << "本书" << endl;
	cout << "-------------" << endl;
	for (int i = 0; i < L->length; i++)
	{
		cout << "ISBN:" << L->elem[i].id << endl;
		cout << "书名:" << L->elem[i].name << endl;
		cout << "价格:" << L->elem[i].price << endl;
		cout << "----------------------" << endl;
	}
}
void PrintInfo(Book e)
{
	cout << "-------------" << endl;
	cout << "ISBN:" << e.id << endl;
	cout << "书名:" << e.name << endl;
	cout << "价格:" << e.price << endl;
	cout << "-------------" << endl;
}


