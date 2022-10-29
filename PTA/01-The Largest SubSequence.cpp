// TITLE: 最大子列和问题-贪心算法
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// NOTE:贪心算法;
int MaxSubSeqSum(int A[], int N)
{
    int ThisSum = 0, MaxSum = 0;
    for (int i = 0; i < N; ++i)
    {
        ThisSum += A[i];
        MaxSum = ThisSum > MaxSum ? ThisSum : MaxSum;
        if (ThisSum < 0)
        {
            ThisSum = 0;
        }
    }
    return MaxSum;
}

int main()
{
    int N;
    int *A;
    cin >> N;
    A = new int[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    cout << MaxSubSeqSum(A, N);

    delete (A);

    return 0;
}