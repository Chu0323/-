#include <iostream>
using namespace std;
//ϡ�����ʽ������
/*
Ax = 7 + 3x + 9x^8 + 5x^17
Bx = 8x + 22x^7 - 9x^8
*/
typedef struct Pnode
{
	float coef; //ϵ��
	int expn; //ָ��
	struct Pnode* next;
} Pnode, *Polynomial;
void createPolyn(Polynomial& L, int n)
{
	L = new Pnode; //�ڶ�������һ������
	L->next = NULL;

	for (int i = 0; i < n; i++)
	{
		Polynomial s = new Pnode; //�����½��
		cin >> s->coef >> s->expn;
		Pnode* p, * q;
		p = L;
		q = p->next;
		while (q && q->expn < s->expn)
		{
			p = q;
			q = q->next;
		}
		s->next = q;
		p->next = s;	
	}
}
void AddPolyn(Polynomial& L1, Polynomial &L2)
{
	Pnode* p1, * p2, *p3, *r;
	p1 = L1->next;
	p2 = L2->next;
	p3 = L1;
	while (p1 && p2)
	{
		if (p1->expn == p2->expn)
		{
			p1->coef += p2->coef;
			if (p1->coef != 0)
			{
				p3->next = p1;
				p3 = p1;
				p1 = p1->next;
				r = p2;
				p2 = p2->next;
				delete r;
			}
			else
			{
				r = p1;
				p1 = p1->next;
				delete r;
				r = p2;
				p2 = p2->next;
				delete r;
			}
		}
		else if (p1->expn < p2->expn)
		{
			p3->next = p1;
			p3 = p1;
			p1 = p1->next;
		}
		else
		{
			p3->next = p2;
			p3 = p2;
			p2 = p2->next;
		}
	}
	p3->next = p1 ? p1 : p2;
	delete L2;
}
void printPolyn(Polynomial& L1)
{
	Pnode* p;
	p = L1->next;
	while (p)
	{
		cout << "coef:" << p->coef << "\texpn:" << p->expn << endl;
		p = p->next;
	}
}
int main(void)
{
	Polynomial L1, L2;
	cout << "�������һ������ʽ��" << endl;
	createPolyn(L1, 4);
	cout << "������ĵ�һ������ʽΪ��" << endl;
	printPolyn(L1);
	cout << "������ڶ�������ʽ��" << endl;
	createPolyn(L2, 3);
	cout << "������ĵڶ�������ʽΪ��" << endl;
	printPolyn(L2);
	cout << "��������ʽ��Ӻ�" << endl;
	AddPolyn(L1, L2);
	printPolyn(L1);

	system("pause");
	return 0;
}