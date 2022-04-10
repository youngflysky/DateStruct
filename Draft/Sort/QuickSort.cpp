#include <iostream>
#include <cstdlib>
using namespace std;

void QuickSort(int arr[], int low, int high)
{
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