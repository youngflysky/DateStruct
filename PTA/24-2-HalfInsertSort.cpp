// TITLE:折半插入排序;
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

void HalfInsertSort(int A[], int N)
{
    int p, temp;
    int low, mid, high;
    for (p = 1; p < N; ++p)
    {
        temp = A[p];
        low = 0, high = p - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (A[mid] > temp)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        for (int j = p; j > high + 1; --j)
        {
            A[j] = A[j - 1];
        }
        A[high + 1] = temp;
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

    HalfInsertSort(Num, N);
    PrintArray(Num, N);

    return 0;
}
