#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

typedef struct Node
{
    int address;
    int data;
    int next;
} Node;
Node *createList(int n = 1)
{
    Node *s;
    s = (Node *)malloc(n * sizeof(Node));
    s[n - 1].next = NULL;
    return s;
}

void reverseK(Node arr[], int K, int i = 0)
{
    int j = i + K - 1;
    int t = i;
    for (; i < j; ++i, --j)
    {
        Node temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void printArr(Node *arr, int N)
{
    int i = 0;
    for ( i = 0; i < N - 1; ++i)
    {
        cout  << setw(5) << setfill('0') << arr[i].address << ' ' << arr[i].data << ' '  << setw(
                  5) << setfill('0') << arr[i].next << endl;
    }
    cout << setw(5) << setfill('0') << arr[i].address << ' ' << arr[i].data << ' ' << -1;
    return;

}

int main() {
    int Head, N, K;
    cin >> Head >> N >> K;

    Node *arr = createList(N);
    for (int i = 0; i < N ; ++i)
    {
        cin >> (arr[i].address) >> (arr[i].data )  >> (arr[i].next);
    }

    int i = 0;
    while (Head != -1)
    {
        int j = i;
        for (j;; ++j)
        {
            if (arr[j].address == Head)
            {
                Node temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                Head = temp.next;
                ++i;
                break;
            }
        }
    }
    N = i;

    for (int i = 0; i + K - 1 < N; i += K)
    {
        reverseK(arr, K, i);
    }
    for (int i = 0; i < N - 1; ++i)
    {
        arr[i].next = arr[i + 1].address;
    }

    printArr(arr, N);



    return 0;
}
