//#include <iostream>
#include "Link_list.h"
/*
����ҳ�����������������������ɾ�Ĳ������Ǿ��ʺ������Ա�Ҳ�����飻�����������
*/
//����ʵ��ͼ�����
int main(void)
{
	//����Bookʵ��
	Book b1 = { "7-5605-0244-X/O", "Ӧ�÷�������", 9 };
	Book b2 = { "978-7-5640-3189-3", "�������", 36 };
	Book b3 = { "978-7-04-062291-1", "��ʱ���й���ɫ�������������ʵ��", 29 };
	Book b4 = { "978-7-302-64242-8", "����֮��", 79 };
	Book b5 = { "978-7-5606-3223-0", "����ϵͳ��������", 28 };
	//��������L
	LinkList L;
	//InitList(L);
	//CreateList_H(L, 2);
	CreateList_L(L, 2);
	//if (InitList(L)) //��ʼ������
	//{
	//	cout << "�����ʼ�����" << endl;
	//	if (IsEmpty(L))
	//		cout << "����ĵ�ǰ����Ϊ:" << L->length << endl;
	//}
	////����Ԫ��
	//InsertList(L, 1, b1);
	//InsertList(L, 2, b2);
	//InsertList(L, 3, b3);
	PrintLinkList(L);
	//int ret = ListLength(L);
	//cout << "��ʱ����ĳ���Ϊ:" << L->length << endl;
	////��ȡ�����ϵ�2��λ���ϵ�Ԫ��
	//Book e;
	////ɾ���������
	//DeleteList(L, 2, e);
	//cout << "��ӡ ɾ���������" << endl;
	//PrintLinkList(L);



	DestoryList(L);
	
	system("pause");
	return 0;
}