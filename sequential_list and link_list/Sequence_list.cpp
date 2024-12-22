#include <iostream>
#include "Sequence_list.h"
//����һ���յ����Ա�L
Status InitList(Sqlist *L)
{
	L->length = 0;
	L->elem = (Book*)malloc(sizeof(Book) * MAX_SIZE);
	
	if (!L->elem) //�����ֵʧ��(�ڴ治��),L->elem = NULL
	{
		exit(OVERFLOW);
		//�洢����ʧ�ܣ�����״̬���ϵͳ����0ֵ��ʾ�쳣
	}
	return true;
}
//ɾ�����Ա�
void DestroyList(Sqlist* L)
{
	if (L->elem)
	{
		free(L->elem); //�����ظ��ͷ�
		L->elem = NULL; //Ϊ�˱�����������ͷź���ڴ�,��û���ָ�븳ֵΪNULL
	}
	L->length = 0;
}
//������Ա�
void ClearList(Sqlist* L)
{
	L->length = 0;
}
//��ȡ���Ա�ĳ���
int GetListLength(Sqlist* L)
{
	return L->length;
}
//�ж����Ա��Ƿ�Ϊ��
int IsEmpty(Sqlist* L)
{
	if (!L->length)
		return true;
	else
		return false;
}
//��ȡ���Ա��i��λ���ϵ�Ԫ��
int GetElem(Sqlist* L, int i, Book& e)
{
	if (IsEmpty(L)) //���Ϊ�գ��򷵻�false
		return false;
	//������Ա�Ϊ�գ�����i�Ƿ�Ϸ�
	if (i < 1 || i > L->length)
		return false;
	e = L->elem[i - 1];
	return true;
}
//����==�����
bool operator==(Book &e1, Book &e2)
{
	if (!strcmp(e1.id, e2.id) && !strcmp(e1.name, e2.name) && e1.price == e2.price)
		return true;
	return false;
}
//��ѯһ��Ԫ�������Ա��ڵڼ���λ��
int LocateElem(Sqlist* L, Book e)
{
	if (IsEmpty(L)) //���Ϊ�գ��򷵻�false
		return 0;
	for (int i = 0; i < L->length; i++)
	{
		if (L->elem[i] == e)
			return i + 1;
	}
	return ERROR;
}
//��ѯһ��Ԫ�ص�ǰ��
int PriorElem(Sqlist* L, Book cur_e, Book& pre_e)
{
	if (IsEmpty(L)) //���Ϊ�ջ��ߵ�һ��Ԫ�ؾ���cur_e���򷵻�false
		return false;
	if (L->elem[0] == cur_e)
		return false;
	int ret = LocateElem(L, cur_e);
	pre_e = L->elem[ret - 2];
	return true;
}
//��ѯһ��Ԫ�صĺ��
int NextElem(Sqlist* L, Book cur_e, Book& next_e)
{
	if (IsEmpty(L)) //���Ϊ�ջ������һ��Ԫ�ؾ���cur_e���򷵻�false
		return false;
	if (L->elem[L->length - 1] == cur_e)
		return false;
	int ret = LocateElem(L, cur_e);
	next_e = L->elem[ret];
	return true;
}
//��i�ϲ���Ԫ��
int ListInsert(Sqlist* L, int i, Book e)
{
	//�����ж�i�ϲ��Ϸ�
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
//ɾ����i��λ���ϵ�Ԫ��
int ListDelete(Sqlist* L, int i)
{
	if (i < 1 || i > L->length)
		return false;
	for (int j = i - 1; j < L->length - 1; j++)
		L->elem[j] = L->elem[j + 1];
	L->length -= 1;
	return true;
}
//˳���ĺϲ�
void Union(Sqlist* La, Sqlist* Lb)
{
	//����Lb��Ԫ�أ��������La�У��Ͳ���
	int la_len = La->length;
	int lb_len = Lb->length;
	for (int j = 0; j < lb_len; j++)
	{
		int ret = LocateElem(La, Lb->elem[j]);
		if (ret == ERROR)
		{
			ListInsert(La, ++la_len, Lb->elem[j]);
			la_len = La->length; //�������Ա�La�ĳ���
		}
	}
}
//char ����Ŀ���
void strcopy(char arr1[], char arr2[])
{
	int len = strlen(arr2);
	for (int i = 0; i < len; i++)
	{
		arr1[i] = arr2[i];
	}
	arr1[len] = '\0';
}

//�����ĺϲ�
/*��֪���Ա�La��Lb������Ԫ�ذ�price�ǵݼ���������
��Ҫ��La��Lb�鲢Ϊһ���µ����Ա�Lc,��Lc�е�����Ԫ���԰�ֵ�ǵݼ���������*/
void Sequential_Union(Sqlist* La, Sqlist* Lb, Sqlist* Lc)
{
	int la_len = La->length;
	int lb_len = Lb->length;
	Book* pa, * pb, * pc, *pa_last, *pb_last;
	pa = La->elem;
	pb = Lb->elem;
	pa_last = La->elem + la_len; //ָ��������һ��Ԫ�ص���һ��λ��
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
//��ӡ���Ա��е���Ϣ
void PrintList(Sqlist* L)
{
	cout << "����" << L->length << "����" << endl;
	cout << "-------------" << endl;
	for (int i = 0; i < L->length; i++)
	{
		cout << "ISBN:" << L->elem[i].id << endl;
		cout << "����:" << L->elem[i].name << endl;
		cout << "�۸�:" << L->elem[i].price << endl;
		cout << "----------------------" << endl;
	}
}
void PrintInfo(Book e)
{
	cout << "-------------" << endl;
	cout << "ISBN:" << e.id << endl;
	cout << "����:" << e.name << endl;
	cout << "�۸�:" << e.price << endl;
	cout << "-------------" << endl;
}


