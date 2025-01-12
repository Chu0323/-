#include <iostream>
#include "sequential_stack.h"
using namespace std;
//表达式求值
//根据运算符优先级，对表达式求值
//假设任何一个算术表达式都由操作数（常量和变量）、算术运算符（ + 、 - 、 * 、 / ）和界限符（括号、表达式结束符‘#’、虚设的表达式起始符‘#’）组成。后两者统称为算符。
//eg :
//1+2/1#


//基于顺序栈的表达式求值

//操作数只能是一位数，而且运算结果不能大于9
//只能进行简单的加减乘除，而且只能进行整除
//不能满足（[之类的运算
int main(void)
{
	Sqstack OPTR, OPND;
	SElemType result = EvaluateExpression(OPTR, OPND);
	cout << result << endl;
	system("pause");
	return 0;
}