#include <iostream>
#include "sequential_stack.h"
using namespace std;
//���ʽ��ֵ
//������������ȼ����Ա��ʽ��ֵ
//�����κ�һ���������ʽ���ɲ������������ͱ������������������ + �� - �� * �� / ���ͽ��޷������š����ʽ��������#��������ı��ʽ��ʼ����#������ɡ�������ͳ��Ϊ�����
//eg :
//1+2/1#


//����˳��ջ�ı��ʽ��ֵ

//������ֻ����һλ�����������������ܴ���9
//ֻ�ܽ��м򵥵ļӼ��˳�������ֻ�ܽ�������
//�������㣨[֮�������
int main(void)
{
	Sqstack OPTR, OPND;
	SElemType result = EvaluateExpression(OPTR, OPND);
	cout << result << endl;
	system("pause");
	return 0;
}