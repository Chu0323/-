#include <iostream>
#include "Sequence_list.h"
/*
如果我常用来检索，而很少用于增删改操作，那就适合用线性表，也即数组；否则就用链表
*/
//顺序表实现图书管理
int main(void)
{
	//创建Book实例
	Book b1 = { "7-5605-0244-X/O", "应用泛函分析", 9 };
	Book b2 = { "978-7-5640-3189-3", "矩阵分析", 36 };
	Book b3 = { "978-7-04-062291-1", "新时代中国特色社会主义理论与实践", 29 };
	Book b4 = { "978-7-302-64242-8", "控制之美", 79 };
	Book b5 = { "978-7-5606-3223-0", "线性系统基础理论", 28 };
	//创建顺序表
	Sqlist* L1 = new Sqlist;
	Sqlist* L2 = new Sqlist;
	Sqlist* L3 = new Sqlist;
	InitList(L1);
	InitList(L2);
	InitList(L3);
	//在线性表中插入元素
	ListInsert(L1, 1, b1);
	ListInsert(L1, 2, b3);
	ListInsert(L1, 3, b2);
	cout << "打印线性表L1" << endl;
	//打印线性表
	PrintList(L1);

	ListInsert(L2, 1, b5);
	ListInsert(L2, 2, b3);
	ListInsert(L2, 3, b4);
	cout << "打印线性表L2" << endl;
	PrintList(L2);
	cout << "有序表的合并" << endl;
	Sequential_Union(L1, L2, L3);
	PrintList(L3);
	
	delete L1;
	delete L2;
	delete L3;
	system("pause");
	return 0;
}
