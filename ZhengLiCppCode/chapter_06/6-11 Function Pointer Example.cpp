// 6_11.cpp ����ָ��ʵ��

#include <iostream>
using namespace std;

typedef int (*cacuP)(int, int); // NOTE:ͨ�� typedef �ܹ���ָ�뺯���Ķ���

int compute(int a, int b, cacuP func) // README:ʹ��ָ�뺯����Ϊ�����β�
{
	return func(a, b);
}

int max(int a, int b) // �����ֵ
{
	return ((a > b) ? a : b);
}
int min(int a, int b) // ����Сֵ
{
	return ((a < b) ? a : b);
}
int sum(int a, int b) // ���
{
	return a + b;
}

int main()
{

	int a, b, res;
	cout << "����������a��";
	cin >> a;
	cout << "����������b��";
	cin >> b;

	res = compute(a, b, &max);
	cout << "Max of " << a << " and " << b << " is " << res << endl;
	res = compute(a, b, &min);
	cout << "Min of " << a << " and " << b << " is " << res << endl;
	res = compute(a, b, &sum);
	cout << "Sum of " << a << " and " << b << " is " << res << endl;
}