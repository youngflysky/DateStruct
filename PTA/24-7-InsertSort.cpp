// TITLE:二路归并排序
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void PrintArray(int A[], int N);

void Merge(int A[], int left, int mid, int right)
{
    int len = right - left + 1;
    int *L = new int[len];
    int midL = (right - left) / 2; // NOTE:一定要注意子列划分的一致性;
    for (int i = left; i <= right; ++i)
    {
        L[i - left] = A[i];
    }

    int i, p1, p2;
    i = left, p1 = 0, p2 = midL + 1;
    while (p1 <= midL && p2 < len)
    {
        if (L[p1] <= L[p2])
        {
            A[i++] = L[p1++];
        }
        else
        {
            A[i++] = L[p2++];
        }
    }

    while (p1 <= midL)
    {
        A[i++] = L[p1++];
    }
    while (p2 < len)
    {
        A[i++] = L[p2++];
    }

    delete L;
}

void MergeSort(int A[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = (left + right) / 2;
    MergeSort(A, left, mid);
    MergeSort(A, mid + 1, right);
    Merge(A, left, mid, right); // NOTE:只有一个递归入口
}

void Merge_Sort(int A[], int N)
{
    int left = 0;
    int right = N - 1;
    MergeSort(A, left, right);
}

int main()
{
    int N;
    cin >> N;
    int *Num = new int[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> Num[i];
    }

    Merge_Sort(Num, N);
    PrintArray(Num, N);

    delete Num;

    return 0;
}

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
