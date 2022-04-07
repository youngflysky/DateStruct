#include <iostream>
using namespace std;
#define maxSize 1005

bool isPopSequence(int length, int capacity)	//模拟数组法
{
	int GivenARR[maxSize] = { 0 };
	for (int i = 0; i < length; ++i)
	{
		cin >> GivenARR[i];
	}
	int stack[maxSize] = { 0 }; int top = -1;
	int p = 0;		//P 用来标记已经入栈的数字以及是否进行入栈操作,初始化为 0
	for (int i = 0; i < length; ++i)//从第1个数字依次开始进行处理
	{
		if (GivenARR[i] <= p) //若当前数字小于P,执行出栈操作
		{
			if (top == -1 || stack[top--] != GivenARR[i]) //若栈空无法出栈,或出栈数字与当前数字不等, return false
			{
				return false;
			}
		}
		else
		{
			for (int j = p + 1; j <= GivenARR[i]; ++j)//若当前数字大于 P, 将 P 和 当前数字间的所有数入栈
			{
				stack[++top] = j;
			}
			if (top >= capacity)//若 栈溢出, return false
			{
				return false;
			}
			else
			{
				top--;					//否则执行出栈操作
				p = GivenARR[i]; //并更新 P 为当前数字
			}
		}
	}
	return true;
}

int main()
{
	int capacity, length, number;
	cin >> capacity >> length >> number;

	int result[maxSize] = { 0 };	//通过结果数组暂存判断结果,方便连续输出

	for (int i = 0; i < number; ++i)
	{
		if (isPopSequence(length, capacity))
		{
			result[i] = 1;
		}
	}
	for (int i = 0; i < number; ++i)
	{
		if (result[i])
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}

	return 0;
}