/*
����ת��
ʮ��������N����������d(�����ˡ�ʮ��)��ת��
ת������
eg: ʮ������159ת���ɰ˽�����
159/8  result  remainder
		19		7
19/8	2		3
2/8		0		2
�˽����� 237
�Ƚ�ջ�ĺ���������ջ�������(����ȳ�)
*/

//������ջ�Ľ���ת��,�԰˽���Ϊ��
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