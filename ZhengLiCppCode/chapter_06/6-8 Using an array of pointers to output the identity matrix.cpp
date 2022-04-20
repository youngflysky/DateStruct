// 6_8.cpp 利用指针数组输出单位矩阵

#include <cstdlib>
#include <iostream>
using namespace std;

int *array(int n = 1)
{
	int *line;
	line = (int *)malloc(n * sizeof(int));
	return line;
}

int main()
{
	// int line1[] = {1, 0, 0}; //定义数组，矩阵的第一行
	// int line2[] = {0, 1, 0}; //定义数组，矩阵的第二行
	// int line3[] = {0, 0, 1}; //定义数组，矩阵的第三行

	//定义整型指针数组并初始化
	int *pLine[9]; // README:利用指针数组存储下三角矩阵

	for (int i = 0; i < 9; ++i)
	{
		pLine[i] = array(i + 1);
		for (int j = 0; j <= i; ++j)
		{
			pLine[i][j] = (j + 1) * (i + 1);
		}
	}

	cout << "Multiplication formula table:" << endl; //输出单位矩阵
	for (int i = 0; i < 9; i++)
	{								 //对指针数组元素循环
		for (int j = 0; j <= i; j++) //对矩阵每一行循环
			cout << pLine[i][j] << " ";
		cout << endl;
	}
	return 0;
}
