#include "Link_list.h"
//链表初始化
Status InitList(LinkList& L) //L是一个指向头结点的指针
{
	L = (LinkList)new Lnode; //new失败后会直接抛出异常
	if (!L)
		return false; //所以这里其实不用判断。但是C语言使用malloc需要进行判断
	L->isHead = 1; //带头结点的单向链表
	L->length = 0; //头结点的数据区存放链表长度
	L->next = NULL;
	return true;
}
//判断链表是否为空
int IsEmpty(LinkList L)
{
	if (!L->next)
		return true; //其实还可以检查头结点数据区存放的链表长度
	return false;
}
//销毁链表
void DestoryList(LinkList &L) //头结点不要
{
	Lnode* p;
	while (L) //L != NULL
	{
		p = L;
		L = p->next;
		delete p;
	}
}
//清空链表
int ClearList(LinkList &L) //保留头结点
{
	Lnode* p, * q;
	p = L->next;
	while (p)
	{
		q = p;
		p = q->next;
		delete q;
	}
	return IsEmpty(L);
}
//获取链表长度
int ListLength(LinkList L)
{
	int len = 0;
	Lnode* p;
	p = L->next;
	while (p)
	{
		++len;
		p = p->next;
	}
	return len;
}
//char数组的拷贝 char* arr1 is destination, char* arr2 is source.
int strcopy(char arr1[], char arr2[])
{
	int len = (int)strlen(arr2);
	for (int i = 0; i < len; i++)
	{
		arr1[i] = arr2[i];
	}
	arr1[len] = '\0';
	if (!strcmp(arr1, arr2)) //成功拷贝，则strcmp返回0
		return true;
	return false;
}
//Book结构体的拷贝
int bookcpy(Book &b1, Book b2)
{
	if (!strcopy(b1.id, b2.id)) //拷贝失败
		return false;
	if (!strcopy(b1.name, b2.name)) //拷贝失败
		return false;
	b1.price = b2.price;
	return true;
}
//获取链表第i个位置上的元素
int GetElem(LinkList &L, int i, Book &e)
{

	Lnode* p;
	p = L;
	if (i < 1 || i > p->length)
		return false;
	for (int j = 1; j <= i; j++)
	{
		p = p->next;
	}
	bookcpy(e, p->data);
	return true;
}
//重载==运算符
int operator==(Book e1, Book e2)
{
	if (!strcmp(e1.id, e2.id) && !strcmp(e1.name, e2.name) && e1.price == e2.price)
		return true;
	return false;
}
//查找：某个元素在链表中的位置
int LocateElem(LinkList &L, Book e)
{
	Lnode* p;
	int pos = 1;
	p = L->next;
	while (p)
	{
		if (p->data == e)
		{
			break;
		}
		else
		{
			p = p->next;
			++pos;
		}
	}
	if (!p)
		return false;
	else
		return pos;
}
//在第i个位置上插入元素e
int InsertList(LinkList &L, int i, Book e)
{
	if (i < 1 || i > L->length + 1)
		return false;
	Lnode* s, *p;
	s = new Lnode;
	bookcpy(s->data, e);
	s->next = NULL;

	int pos = 0;
	p = L;
	while (p->next)
	{
		if (pos == i - 1)
			break;
		p = p->next;
		++pos;
	}
	s->next = p->next;
	p->next = s;
	L->length++;
	return true;
}
//删除链表上第i个位置的元素e
int DeleteList(LinkList &L, int i, Book& e)
{
	if (i < 1 || i > L->length)
		return false;
	Lnode *s, * p;

	int len = 0;
	p = L;
	while (p->next && len != i - 1)
	{
		p = p->next;
		++len;
	}
	s = p->next;
	if (s == NULL)
		return false;
	else
		bookcpy(e, s->data); //我不明白这里为啥会有警告
	p->next = s->next;
	delete s;
	--L->length;
	return true;
}
//头插法创建链表
void CreateList_H(LinkList &L, int n)
{
	Lnode* p;
	L = (LinkList)new Lnode;
	L->length = 0;
	L->next = NULL;
	for (int i = 1; i <= n; i++)
	{
		p = (Lnode*)new Lnode;
		cout << "请输入ISBN:" << endl;
		cin >> p->data.id;
		cout << "请输入书名:" << endl;
		cin >> p->data.name;
		cout << "请输入价格:" << endl;
		cin >> p->data.price;
		p->next = L->next;
		L->next = p;
		++L->length;
	}
}
//尾插法创建链表
void CreateList_L(LinkList &L, int n)
{
	Lnode* p, *r;
	L = (LinkList)new Lnode;
	L->length = 0;
	L->next = NULL;
	r = L->next;
	for (int i = 1; i <= n; i++)
	{
		p = (Lnode*)new Lnode;
		cout << "请输入ISBN:" << endl;
		cin >> p->data.id;
		cout << "请输入书名:" << endl;
		cin >> p->data.name;
		cout << "请输入价格:" << endl;
		cin >> p->data.price;
		p->next = NULL;
		if (!L->next) //如果L->next为空
		{
			L->next = p;
			r = L->next;
		}
		else if (r) //如果r不为空
		{
			r->next = p;
			r = p;
		}
	}
}
//打印链表
void PrintLinkList(LinkList L)
{
	Lnode* p;
	p = L->next;
	cout << "--------" << endl;
	while (p)
	{
		cout << "ISBN:" << p->data.id << endl;
		cout << "书名:" << p->data.name << endl;
		cout << "price:" << p->data.price << endl;
		cout << "--------" << endl;
		p = p->next;
	}
}
//打印元素
void PrintElem(Book e)
{
	cout << "--------" << endl;
	cout << "ISBN:" << e.id << endl;
	cout << "书名:" << e.name << endl;
	cout << "price:" << e.price << endl;
	cout << "--------" << endl;
}
