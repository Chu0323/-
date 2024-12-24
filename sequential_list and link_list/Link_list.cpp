#include "Link_list.h"
//�����ʼ��
Status InitList(LinkList& L) //L��һ��ָ��ͷ����ָ��
{
	L = (LinkList)new Lnode; //newʧ�ܺ��ֱ���׳��쳣
	if (!L)
		return false; //����������ʵ�����жϡ�����C����ʹ��malloc��Ҫ�����ж�
	L->isHead = 1; //��ͷ���ĵ�������
	L->length = 0; //ͷ�������������������
	L->next = NULL;
	return true;
}
//�ж������Ƿ�Ϊ��
int IsEmpty(LinkList L)
{
	if (!L->next)
		return true; //��ʵ�����Լ��ͷ�����������ŵ�������
	return false;
}
//��������
void DestoryList(LinkList &L) //ͷ��㲻Ҫ
{
	Lnode* p;
	while (L) //L != NULL
	{
		p = L;
		L = p->next;
		delete p;
	}
}
//�������
int ClearList(LinkList &L) //����ͷ���
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
//��ȡ������
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
//char����Ŀ��� char* arr1 is destination, char* arr2 is source.
int strcopy(char arr1[], char arr2[])
{
	int len = (int)strlen(arr2);
	for (int i = 0; i < len; i++)
	{
		arr1[i] = arr2[i];
	}
	arr1[len] = '\0';
	if (!strcmp(arr1, arr2)) //�ɹ���������strcmp����0
		return true;
	return false;
}
//Book�ṹ��Ŀ���
int bookcpy(Book &b1, Book b2)
{
	if (!strcopy(b1.id, b2.id)) //����ʧ��
		return false;
	if (!strcopy(b1.name, b2.name)) //����ʧ��
		return false;
	b1.price = b2.price;
	return true;
}
//��ȡ�����i��λ���ϵ�Ԫ��
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
//����==�����
int operator==(Book e1, Book e2)
{
	if (!strcmp(e1.id, e2.id) && !strcmp(e1.name, e2.name) && e1.price == e2.price)
		return true;
	return false;
}
//���ң�ĳ��Ԫ���������е�λ��
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
//�ڵ�i��λ���ϲ���Ԫ��e
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
//ɾ�������ϵ�i��λ�õ�Ԫ��e
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
		bookcpy(e, s->data); //�Ҳ���������Ϊɶ���о���
	p->next = s->next;
	delete s;
	--L->length;
	return true;
}
//ͷ�巨��������
void CreateList_H(LinkList &L, int n)
{
	Lnode* p;
	L = (LinkList)new Lnode;
	L->length = 0;
	L->next = NULL;
	for (int i = 1; i <= n; i++)
	{
		p = (Lnode*)new Lnode;
		cout << "������ISBN:" << endl;
		cin >> p->data.id;
		cout << "����������:" << endl;
		cin >> p->data.name;
		cout << "������۸�:" << endl;
		cin >> p->data.price;
		p->next = L->next;
		L->next = p;
		++L->length;
	}
}
//β�巨��������
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
		cout << "������ISBN:" << endl;
		cin >> p->data.id;
		cout << "����������:" << endl;
		cin >> p->data.name;
		cout << "������۸�:" << endl;
		cin >> p->data.price;
		p->next = NULL;
		if (!L->next) //���L->nextΪ��
		{
			L->next = p;
			r = L->next;
		}
		else if (r) //���r��Ϊ��
		{
			r->next = p;
			r = p;
		}
	}
}
//��ӡ����
void PrintLinkList(LinkList L)
{
	Lnode* p;
	p = L->next;
	cout << "--------" << endl;
	while (p)
	{
		cout << "ISBN:" << p->data.id << endl;
		cout << "����:" << p->data.name << endl;
		cout << "price:" << p->data.price << endl;
		cout << "--------" << endl;
		p = p->next;
	}
}
//��ӡԪ��
void PrintElem(Book e)
{
	cout << "--------" << endl;
	cout << "ISBN:" << e.id << endl;
	cout << "����:" << e.name << endl;
	cout << "price:" << e.price << endl;
	cout << "--------" << endl;
}
