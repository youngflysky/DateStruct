// TITLE:插入排序;
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

void InsertSort(int A[], int N)
{
    int p, temp, i;
    for (p = 1; p < N; ++p)
    {
        temp = A[p];
        for (i = p; i > 0 && A[i - 1] > temp; --i)
        {
            A[i] = A[i - 1];
        }
        A[i] = temp;
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

    InsertSort(Num, N);
    PrintArray(Num, N);

    return 0;
}
