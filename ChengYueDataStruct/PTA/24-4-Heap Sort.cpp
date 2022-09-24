// TITLE:排序
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MaxSize = 100005;

int Num[MaxSize];

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

// NOTE:每当向一个大顶堆插入一个根节点时，
//调整将此节点向下沉降到正确位置后，重新成为一颗大顶堆;
void PerDown(int A[], int root, int rear)
{
    int parent, child;
    int tmp = A[root];
    for (parent = root; parent * 2 + 1 <= rear; parent = child)
    {
        child = parent * 2 + 1;
        if (child < rear && A[child] < A[child + 1])
        {
            ++child;
        }
        if (A[child] > tmp)
        {
            A[parent] = A[child];
        }
        else
        {
            break;
        }
    }
    A[parent] = tmp;
}

void HeapSort(int A[], int n)
{
    for (int i = n / 2; i >= 0; --i) //构建最大堆;
    {
        PerDown(A, i, n - 1);
    }

    for (int i = n - 1; i >= 1; --i) // NOTE:只需要进行 n-1 趟排序
    {
        int tmp = A[0];
        A[0] = A[i];
        A[i] = tmp;
        PerDown(A, 0, i - 1);
    }
}

int main()
{

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> Num[i];
    }

    HeapSort(Num, N);
    PrintArray(Num, N);

    return 0;
}