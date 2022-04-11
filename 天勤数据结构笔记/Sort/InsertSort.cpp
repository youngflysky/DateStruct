#include <iostream>
#include <cstdlib>
using namespace std;

void InsertSort(int arr[], int n) //时间复杂度 O(n^2)
{
    int i, j;
    int temp;
    for (i = 1; i < n; ++i)
    {
        temp = arr[i];
        for (j = i - 1; j >= 0 && temp < arr[j]; --j)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
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
    InsertSort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}