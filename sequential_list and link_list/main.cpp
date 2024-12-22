#include <iostream>
using namespace std;
#define max_size 100
//两个多项式求和
/*
Pa(x)=10+5x-4x^2+3x^3+2x^4
Pb(x)=-3+8x+4x^2-5x^4+7x^5-2x^6
*/
//输入/存储一个多项式
typedef struct
{
	int *p; //存放多项式系数
	int length; //数组长度
} Polymonial;
Polymonial create_polymonial(void)
{
	Polymonial px;
	px.p = new int[max_size];
	px.length = 0;
	int n;
	cout << "请输入多项式的系数：enter -1 to quit：\n";
	cin >> n;
	while (n != -1)
	{
		px.p[px.length++] = n;
		cin >> n;
	}
	return px;	
}
Polymonial add_polymonial(Polymonial &px, Polymonial &qx)
{
	int pl = px.length;
	int ql = qx.length;
	int n = pl>ql?pl:ql;
	for (int i = 0; i < n; i++)
	{
		if (px.p[i] == -1)
			px.p[i] = 0;
		px.p[i] += qx.p[i];
	}
	px.length = n;
	return px;
}
void print_polymonial(Polymonial &px)
{
	int n = px.length;
	for (int i = 0; i < n; i++)
		cout << px.p[i] << " ";
	cout << endl;
}

int main(void) 
{
	cout << "请输入第一个多项式:" << endl;
	Polymonial px = create_polymonial();
	cout << "请输入第二个多项式:" << endl;
	Polymonial qx = create_polymonial();
	cout << "您输入的第一个多项式为：" << endl;
	print_polymonial(px);
	cout << "您输入的第二个多项式为：" << endl;
	print_polymonial(qx);
	cout << "两个多项式的和为:" << endl;
	add_polymonial(px, qx);
	print_polymonial(px);
	system("pause");
	delete[] px.p, qx.p;
	return 0;
}