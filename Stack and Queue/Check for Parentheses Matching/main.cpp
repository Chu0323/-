#include <iostream>
#include "sequential_stack.h"
using namespace std;
//括号匹配的检验
//假设表达式中允许包含两种括号：圆括号和方括号
//其嵌套的顺序随意，即
//（ 【】（））为正确格式
//【 （】 ） 为错误格式
//先入栈的后匹配，后入栈的先匹配
//检查括号是否匹配


//基于顺序栈
int main(void)
{
	Sqstack s;
	if (Matching(s))
		cout << "格式正确。" << endl;
	else
		cout << "格式错误。" << endl;

	DestoryStack(s);
	system("pause");
	return 0;
}