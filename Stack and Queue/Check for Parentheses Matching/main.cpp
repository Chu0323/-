#include <iostream>
#include "sequential_stack.h"
using namespace std;
//����ƥ��ļ���
//������ʽ����������������ţ�Բ���źͷ�����
//��Ƕ�׵�˳�����⣬��
//�� ����������Ϊ��ȷ��ʽ
//�� ���� �� Ϊ�����ʽ
//����ջ�ĺ�ƥ�䣬����ջ����ƥ��
//��������Ƿ�ƥ��


//����˳��ջ
int main(void)
{
	Sqstack s;
	if (Matching(s))
		cout << "��ʽ��ȷ��" << endl;
	else
		cout << "��ʽ����" << endl;

	DestoryStack(s);
	system("pause");
	return 0;
}