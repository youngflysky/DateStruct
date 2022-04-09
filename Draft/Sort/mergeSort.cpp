#include <iostream>
#include <cstdlib>
using namespace std;

//归并排序

void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; ++i) //建立子链
    {
        L[i] = arr[low + i];
    }
    for (int i = 0; i < n2; ++i)
    {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0;
    int k = 0;
    for (; i < n1 && j < n2; ++k) //子链归并
    {
        if (L[i] < R[j])
        {
            arr[low + k] = L[i++];
        }
        else
        {
            arr[low + k] = R[j++];
        }
    }
    for (; i < n1; ++k)
    {
        arr[low + k] = L[i++];
    }
    for (; j < n2; ++k)
    {
        arr[low + k] = R[j++];
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
    int low = 3, high = 8;
    mergeSort(arr, low, high);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

    return 0;
}