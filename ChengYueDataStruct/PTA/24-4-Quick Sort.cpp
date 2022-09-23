// TITLE:QuickSort
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MaxSize = 100005;
const int CutOff = 20;

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

int FindMidNum(int A[], int left, int right)
{
    int mid = (left + right) / 2;
    if (A[left] > A[mid])
    {
        int tmp = A[left];
        A[left] = A[mid];
        A[mid] = tmp;
    }
    if (A[left] > A[right])
    {
        int tmp = A[left];
        A[left] = A[right];
        A[right] = tmp;
    }
    if (A[mid] > A[right])
    {
        int tmp = A[mid];
        A[mid] = A[right];
        A[right] = tmp;
    }
    int tmp = A[mid];
    A[mid] = A[right - 1];
    A[right - 1] = tmp;
    return tmp;
}

void InsertSort(int A[], int left, int right)
{
    for (int p = left + 1; p <= right; ++p)
    {
        int i = p;
        int tmp = A[i];
        for (; i > left && A[i - 1] > tmp; --i)
        {
            A[i] = A[i - 1];
        }
        A[i] = tmp;
    }
}

void QuickSort(int A[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    if (right - left + 1 < CutOff)
    {
        InsertSort(A, left, right);
        return;
    }
    int pivot = FindMidNum(A, left, right);
    int i = left;
    int j = right - 1;
    for (;;)
    {
        while (i < j && A[++i] < pivot)
        {
        }
        while (i < j && A[--j] > pivot)
        {
        }
        if (i < j)
        {
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
        else
        {
            break;
        }
    }
    {
        int tmp = A[i];
        A[i] = A[right - 1];
        A[right - 1] = tmp;
    }
    QuickSort(A, left, i - 1);
    QuickSort(A, i + 1, right);
}

void Quick_Sort(int A[], int N)
{
    QuickSort(A, 0, N - 1);
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
    Quick_Sort(Num, N);
    PrintArray(Num, N);

    return 0;
}