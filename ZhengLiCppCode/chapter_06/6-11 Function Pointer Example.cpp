// 6_11.cpp 函数指针实例

#include <iostream>
using namespace std;

typedef int (*cacuP)(int, int); // NOTE:通过 typedef 能够简化指针函数的定义

int compute(int a, int b, cacuP func) // README:使用指针函数作为函数形参
{
	return func(a, b);
}

int max(int a, int b) // 求最大值
{
	return ((a > b) ? a : b);
}
int min(int a, int b) // 求最小值
{
	return ((a < b) ? a : b);
}
int sum(int a, int b) // 求和
{
	return a + b;
}

int main()
{

	int a, b, res;
	cout << "请输入整数a：";
	cin >> a;
	cout << "请输入整数b：";
	cin >> b;

	res = compute(a, b, &max);
	cout << "Max of " << a << " and " << b << " is " << res << endl;
	res = compute(a, b, &min);
	cout << "Min of " << a << " and " << b << " is " << res << endl;
	res = compute(a, b, &sum);
	cout << "Sum of " << a << " and " << b << " is " << res << endl;
}