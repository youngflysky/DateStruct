// TITLE:归并排序
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

void Merge(int A[], int left, int mid, int right)
{
    int len1 = mid - left + 1;
    int len2 = right - mid;
    int *L1 = new int[len1];
    int *L2 = new int[len2];
    for (int i = left; i <= mid; ++i)
    {
        L1[i - left] = A[i];
    }
    for (int i = mid + 1; i <= right; ++i)
    {
        L2[i - mid - 1] = A[i];
    }
    int i = left, p1 = 0, p2 = 0;
    for (; p1 < len1 && p2 < len2;)
    {
        if (L1[p1] <= L2[p2])
        {
            A[i++] = L1[p1++];
        }
        else
        {
            A[i++] = L2[p2++];
        }
    }
    if (p1 == len1)
    {
        for (; p2 < len2;)
        {
            A[i++] = L2[p2++];
        }
    }
    else if (p2 == len2)
    {
        for (; p1 < len1;)
        {
            A[i++] = L1[p1++];
        }
    }
    delete (L1);
    delete (L2);
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
    Merge(A, left, mid, right);
}

void Merge_Sort(int A[], int N)
{
    int left = 0;
    int right = N - 1;
    MergeSort(A, left, right);
}

int main()
{
    int Num[MaxSize];
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> Num[i];
    }

    Merge_Sort(Num, N);
    PrintArray(Num, N);

    return 0;
}