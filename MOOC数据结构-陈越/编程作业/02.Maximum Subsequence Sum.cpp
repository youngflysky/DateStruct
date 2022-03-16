#include <iostream>
#include <cstdlib>
using namespace std;

void findMaxSum(int *A, int N)
{
	int maxSum = -1;
	int thisSum = 0;
	int left = 0, right = N - 1, tempLeft = 0;
	for (int i = 0; i < N; ++i)
	{
		thisSum += A[i];

		if (thisSum < 0)
		{
			thisSum = 0;
			tempLeft = i + 1;
		}
		else if (thisSum > maxSum)
		{
			maxSum = thisSum;
			right = i;
			left = tempLeft;
		}
	}
	if (maxSum < 0)
	{
		maxSum = 0;
		cout << maxSum << ' ' << A[0] << ' ' << A[N - 1];
	}
	else
	{
		cout << maxSum << ' ' << A[left] << ' ' << A[right];
	}

}


int main() {

	int N;
	cin >> N;
	int *A = (int *)calloc(N, sizeof(int));//calloc()分配的空间会被初始化为0
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}
	findMaxSum(A, N);
	return 0;
}
