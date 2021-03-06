#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
int *getRand(int arr[], int a = 0, int b = 10)
{
    srand(time(NULL));
    for (int i = 0; i < 20; ++i)
    {
        arr[i] = rand() % (b - a) + a;
        cout << arr[i] << ' ';
    }

    return arr;
}

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
    int arr[20];
    getRand(arr, 0, 20);
    cout << endl;
    BubbleSort(arr, 20);
    for (int i = 0; i < 20; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

    return 0;
}