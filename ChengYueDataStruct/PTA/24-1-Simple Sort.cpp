// TITLE:简单排序算法：冒泡，插入，选择
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

void BubbleSort(int A[], int N);

void InsertSort(int A[], int N);

void SelectSort(int A[], int N); // NOTE:将未排序部分的最小值交换到有序部分的最后;

int main()
{
    int N;
    int Num[MaxSize];
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> Num[i];
    }

    // BubbleSort(Num, N);
    // PrintArray(Num, N);

    // InsertSort(Num, N);
    // PrintArray(Num, N);

    // SelectSort(Num, N);
    // PrintArray(Num, N);

    return 0;
}

void BubbleSort(int A[], int N)
{
    int flag = 1;
    int tmp;
    for (int p = N - 1; p > 0 && flag; --p)
    {
        flag = 0;
        for (int i = 0; i < p; ++i) // NOTE:此处注意数组范围 i<p ，i<=p 数组越界;
        {
            if (A[i] > A[i + 1])
            {
                flag = 1;
                tmp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = tmp;
            }
        }
    }
}

void InsertSort(int A[], int N)
{
    int tmp;
    for (int p = 1; p < N; ++p)
    {
        tmp = A[p];
        int i = p;
        for (; i >= 1 && A[i - 1] > tmp; --i) // NOTE:注意，未进入循环时，A[i]=tmp<=>i=p&&i>0;
        {
            A[i] = A[i - 1];
        }
        A[i] = tmp;
    }
}

void SelectSort(int A[], int N)
{
    int min;
    int tmp;
    for (int p = 0; p < N; ++p)
    {
        min = p;
        for (int i = p; i < N; ++i)
        {
            if (A[i] < A[min])
            {
                min = i;
            }
        }
        tmp = A[p];
        A[p] = A[min];
        A[min] = tmp;
    }
}
