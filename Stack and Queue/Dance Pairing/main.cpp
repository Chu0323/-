#include <iostream>
#include "linear_queue.h"
using namespace std;

//基于循环队列的舞伴问题
int main(void)
{
	SqQueue Mdancers, Fdancers; //分别存放男士和女士
	Person dancer[5] =
	{
		{"张三", "F"},
		{"李四", "M"},
		{"王二", "F"},
		{"麻子", "M"},
		{"赵六", "F"}
	};
	DancePartner(Mdancers, Fdancers, dancer, 5);
	DeleteQueue(Mdancers);
	DeleteQueue(Fdancers);
	system("pause");
	return 0;
}

