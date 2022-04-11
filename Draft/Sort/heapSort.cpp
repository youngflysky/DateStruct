#include <cstdlib>
#include <iostream>
using namespace std;

void heapSort(int arr[], int n);         //堆排序
void Sift(int arr[], int low, int high); //建堆函数

void heapSort(int arr[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; --i) //初始化大顶堆
    {
        Sift(arr, i, n - 1);
    }
    int temp;
    for (i = n - 1; i >= 1; --i) //大顶堆导出的递增数列
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        Sift(arr, 0, i - 1);
    }
    return;
}

void Sift(int arr[], int low, int high) //第 1 个节点编号为 0
{
    int i = low, j = 2 * i + 1;
    int temp = arr[i];
    while (j <= high)
    {
        if (j < high && arr[j] < arr[j + 1]) //定位 j 到左右孩子中较大的一个
        {
            ++j;
        }
        if (arr[j] > temp) // arr【i】 的值已经改变，故必须用 temp
        {
            arr[i] = arr[j];
            i = j;
            j = 2 * i + 1;
        }
        else
        {
            break;
        }
    }
    arr[i] = temp; //上述循环操作执行后，此处的 arr[i] 实际上是最终的 arr[j]
    return;
}

int main()
{
    int arr[10] = {7, 5, 2, 6, 4, 3, 0, 8, 9, 1};
    for (int i = 0; i < 10; ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    heapSort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

    return 0;
}