//#include <iostream>
#include "Link_list.h"
/*
如果我常用来检索，而很少用于增删改操作，那就适合用线性表，也即数组；否则就用链表
*/
//链表实现图书管理
int main(void)
{
	//创建Book实例
	Book b1 = { "7-5605-0244-X/O", "应用泛函分析", 9 };
	Book b2 = { "978-7-5640-3189-3", "矩阵分析", 36 };
	Book b3 = { "978-7-04-062291-1", "新时代中国特色社会主义理论与实践", 29 };
	Book b4 = { "978-7-302-64242-8", "控制之美", 79 };
	Book b5 = { "978-7-5606-3223-0", "线性系统基础理论", 28 };
	//创建链表L
	LinkList L;
	//InitList(L);
	//CreateList_H(L, 2);
	CreateList_L(L, 2);
	//if (InitList(L)) //初始化链表
	//{
	//	cout << "链表初始化完成" << endl;
	//	if (IsEmpty(L))
	//		cout << "链表的当前长度为:" << L->length << endl;
	//}
	////插入元素
	//InsertList(L, 1, b1);
	//InsertList(L, 2, b2);
	//InsertList(L, 3, b3);
	PrintLinkList(L);
	//int ret = ListLength(L);
	//cout << "此时链表的长度为:" << L->length << endl;
	////获取链表上第2个位置上的元素
	//Book e;
	////删除矩阵分析
	//DeleteList(L, 2, e);
	//cout << "打印 删除后的链表" << endl;
	//PrintLinkList(L);



	DestoryList(L);
	
	system("pause");
	return 0;
}