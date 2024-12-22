#include <iostream>
using namespace std;
//稀疏多项式的运算
/*
Ax = 7 + 3x + 9x^8 + 5x^17
Bx = 8x + 22x^7 - 9x^8
*/
typedef struct Pnode
{
	float coef; //系数
	int expn; //指数
	struct Pnode* next;
} Pnode, *Polynomial;
void createPolyn(Polynomial& L, int n)
{
	L = new Pnode; //在堆区创建一个链表
	L->next = NULL;

	for (int i = 0; i < n; i++)
	{
		Polynomial s = new Pnode; //生成新结点
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
	cout << "请输入第一个多项式：" << endl;
	createPolyn(L1, 4);
	cout << "您输入的第一个多项式为：" << endl;
	printPolyn(L1);
	cout << "请输入第二个多项式：" << endl;
	createPolyn(L2, 3);
	cout << "您输入的第二个多项式为：" << endl;
	printPolyn(L2);
	cout << "两个多项式相加后：" << endl;
	AddPolyn(L1, L2);
	printPolyn(L1);

	system("pause");
	return 0;
}
