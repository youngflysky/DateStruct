#include <cstdlib>
#include <iostream>
using namespace std;

void QuickSort(int arr[], int low, int high)
{

    if (low < high)
    {
        int i = low, j = high;
        int temp = arr[i];
        while (i < j)
        {
            while (j > i && arr[j] >= temp)
            {
                --j;
            }
            if (i < j)
            {
                arr[i++] = arr[j];
            }
            while (i < j && arr[i] <= temp)
            {
                ++i;
            }
            if (i < j)
            {
                arr[j--] = arr[i];
            }
        }
        arr[i] = temp;
        QuickSort(arr, low, i - 1);
        QuickSort(arr, j + 1, high);
    }
}

int main()
{
    int arr[10] = {7, 5, 2, 6, 4, 3, 0, 8, 9, 1};
    for (int i = 0; i < 10; ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    QuickSort(arr, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

    return 0;
}