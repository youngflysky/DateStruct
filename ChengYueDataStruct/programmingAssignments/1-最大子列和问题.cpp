#include <iostream>
#define maxSize 100000
using namespace std;

void findMaxSum1(int A[], int N)
{
	int maxSum = 0;
	int thisSum = 0;
	for (int i = 0; i < N; ++i)
	{
		thisSum = 0;
		for (int j = i; j < N; j++)
		{
			thisSum += A[j];
			if (thisSum > maxSum)
			{
				maxSum = thisSum;
			}
		}
	}
	cout << maxSum << endl;
}

void findMaxSum2(int A[], int K)
{
}

//Ì°ÐÄËã·¨
void findMaxSum3(int A[], int N)
{
	int maxSum = 0;
	int thisSum = 0;
	for (int i = 0; i < N; ++i)
	{
		thisSum += A[i];
		if (thisSum > maxSum)
		{
			maxSum = thisSum;
		}
		else if (thisSum < 0)
		{
			thisSum = 0;
		}
	}
	cout << maxSum << endl;
}

int main()
{

	int N;
	cin >> N;
	int A[maxSize];
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	findMaxSum3(A, N);
	return 0;
}
