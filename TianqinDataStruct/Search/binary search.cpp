#include <cstdlib>
#include <iostream>
using namespace std;

int BinarySearch(int arr[], int low, int high, int k)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{

    return 0;
}
