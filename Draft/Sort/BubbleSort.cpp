#include <iostream>
#include <cstdlib>
using namespace std;

//冒泡排序

void BubbleSort(int arr[], int n)
{
    int i = 0, j = 0, flag = 0;
    int temp = 0;
    for (i = n - 1; i >= 1; --i)
    {
        flag = 0;
        for (j = 1; j <= i; ++j)
        {
            if (arr[j - 1] > arr[j])
            {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            return;
        }
    }
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
    BubbleSort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

    return 0;
}