#include <iostream>
#include "Sequence_list.h"
/*
����ҳ�����������������������ɾ�Ĳ������Ǿ��ʺ������Ա�Ҳ�����飻�����������
*/
//˳���ʵ��ͼ�����
int main(void)
{
	//����Bookʵ��
	Book b1 = { "7-5605-0244-X/O", "Ӧ�÷�������", 9 };
	Book b2 = { "978-7-5640-3189-3", "�������", 36 };
	Book b3 = { "978-7-04-062291-1", "��ʱ���й���ɫ�������������ʵ��", 29 };
	Book b4 = { "978-7-302-64242-8", "����֮��", 79 };
	Book b5 = { "978-7-5606-3223-0", "����ϵͳ��������", 28 };
	//����˳���
	Sqlist* L1 = new Sqlist;
	Sqlist* L2 = new Sqlist;
	Sqlist* L3 = new Sqlist;
	InitList(L1);
	InitList(L2);
	InitList(L3);
	//�����Ա��в���Ԫ��
	ListInsert(L1, 1, b1);
	ListInsert(L1, 2, b3);
	ListInsert(L1, 3, b2);
	cout << "��ӡ���Ա�L1" << endl;
	//��ӡ���Ա�
	PrintList(L1);

	ListInsert(L2, 1, b5);
	ListInsert(L2, 2, b3);
	ListInsert(L2, 3, b4);
	cout << "��ӡ���Ա�L2" << endl;
	PrintList(L2);
	cout << "�����ĺϲ�" << endl;
	Sequential_Union(L1, L2, L3);
	PrintList(L3);
	
	delete L1;
	delete L2;
	delete L3;
	system("pause");
	return 0;
}