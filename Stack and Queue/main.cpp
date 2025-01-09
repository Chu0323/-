/*
进制转换
十进制整数N向其他进制d(二、八、十六)的转换
转换法则：
eg: 十进制数159转换成八进制数
159/8  result  remainder
		19		7
19/8	2		3
2/8		0		2
八进制数 237
先进栈的后输出，后进栈的先输出(后进先出)
*/

//基于链栈的进制转换,以八进制为例
#include <iostream>
#include "link_stack.h"
using namespace std;

int main(void)
{
	LinkStack s;
	conversion(s, 159);
	cout << endl;
	DeleteStack(s);
	system("pause");
	return 0;
}