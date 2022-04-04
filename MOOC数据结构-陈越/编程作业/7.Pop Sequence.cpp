#include <iostream>
using namespace std;
#define maxSize 1005

bool isPopSequence(int length, int capacity) {	//ģ�����鷨
	int GivenARR[maxSize] = { 0 };
	for (int i = 0; i < length; ++i) {
		cin >> GivenARR[i];
	}
	int stack[maxSize] = { 0 };
	int top = -1;
	int p = GivenARR[0];
	for (int i = 1; i <= p; ++i) { //ͨ����һ������,��ջ���г�ʼ��
		stack[++top] = i;
	}
	if (top >= capacity) {	//����ʼ��ʱջ�����,�� return false;
		return false;
	}
	for (int i = 0; i < length; ++i) { //�ӵ�1���������ο�ʼ���д���
		if (GivenARR[i] <= p) { //����ǰ����С��P,ִ�г�ջ����
			if (top == -1 || stack[top--] != GivenARR[i]) { //��ջ���޷���ջ,���ջ�����뵱ǰ���ֲ���, return false
				return false;
			}
		} else {
			for (int j = p + 1; j <= GivenARR[i]; ++j) { //����ǰ���ִ��� P, �� P �� ��ǰ���ּ����������ջ
				stack[++top] = j;
			}
			if (top >= capacity) { //�� ջ���, return false
				return false;
			} else {
				top--;					//����ִ�г�ջ����
				p = GivenARR[i]; //������ P Ϊ��ǰ����
			}
		}
	}
	return true;
}

int main() {
	int capacity, length, number;
	cin >> capacity >> length >> number;

	int result[maxSize] = { 0 };	//ͨ����������ݴ��жϽ��,�����������

	for (int i = 0; i < number; ++i) {
		if (isPopSequence(length, capacity)) {
			result[i] = 1;
		}
	}
	for (int i = 0; i < number; ++i) {
		if (result[i]) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}