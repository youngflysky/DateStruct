// 6_8.cpp ����ָ�����������λ����

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
	// int line1[] = {1, 0, 0}; //�������飬����ĵ�һ��
	// int line2[] = {0, 1, 0}; //�������飬����ĵڶ���
	// int line3[] = {0, 0, 1}; //�������飬����ĵ�����

	//��������ָ�����鲢��ʼ��
	int *pLine[9]; // README:����ָ������洢�����Ǿ���

	for (int i = 0; i < 9; ++i)
	{
		pLine[i] = array(i + 1);
		for (int j = 0; j <= i; ++j)
		{
			pLine[i][j] = (j + 1) * (i + 1);
		}
	}

	cout << "Multiplication formula table:" << endl; //�����λ����
	for (int i = 0; i < 9; i++)
	{								 //��ָ������Ԫ��ѭ��
		for (int j = 0; j <= i; j++) //�Ծ���ÿһ��ѭ��
			cout << pLine[i][j] << " ";
		cout << endl;
	}
	return 0;
}
