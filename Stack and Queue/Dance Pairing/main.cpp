#include <iostream>
#include "linear_queue.h"
using namespace std;

//����ѭ�����е��������
int main(void)
{
	SqQueue Mdancers, Fdancers; //�ֱ�����ʿ��Ůʿ
	Person dancer[5] =
	{
		{"����", "F"},
		{"����", "M"},
		{"����", "F"},
		{"����", "M"},
		{"����", "F"}
	};
	DancePartner(Mdancers, Fdancers, dancer, 5);
	DeleteQueue(Mdancers);
	DeleteQueue(Fdancers);
	system("pause");
	return 0;
}

