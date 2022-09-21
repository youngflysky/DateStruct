#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MaxSize = 100005;
void PrintArray(int A[], int N)
{

    for (int i = 0;; ++i)
    {
        cout << A[i];
        if (i >= N - 1)
        {
            cout << endl;
            return;
        }
        cout << ' ';
    }
}

void ShellSort(int A[], int N)
{
    vector<int> stackD;
    for (int i = 1; i < N; i = i * 2 + 1)
    {
        stackD.push_back(i);
    }
    for (int v = stackD.size() - 1; v >= 0; --v)
    {
        int D = stackD[v];
        for (int p = D; p < N; ++p)
        {
            int i = p;
            int tmp = A[i];
            for (; i >= D && A[i - D] > tmp; i -= D)
            {
                A[i] = A[i - D];
            }
            A[i] = tmp;
        }
    }
}

int main()
{
    int N;
    int Num[MaxSize];
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> Num[i];
    }

    ShellSort(Num, N);
    PrintArray(Num, N);

    return 0;
}