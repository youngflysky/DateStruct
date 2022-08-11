// TITLE:堆中的路径

#include <iostream>
#include <vector>
using namespace std;
#define MinVal -10001

typedef struct HeapStruct *MinHeap;
struct HeapStruct
{
    int *data;
    int size;
    int capacity;
};

MinHeap IniteMinHeap(int capacity)
{
    MinHeap MinH = new struct HeapStruct;
    MinH->data = new int[capacity + 1];
    MinH->data[0] = MinVal;
    MinH->size = 0;
    MinH->capacity = capacity + 1;
    return MinH;
}

void InsertHeap(int data, MinHeap &MinH)
{
    int i = ++MinH->size;
    for (; MinH->data[i / 2] > data; i /= 2)
    {
        MinH->data[i] = MinH->data[i / 2];
    }
    MinH->data[i] = data;
}

MinHeap CreateHeap(int capacity)
{
    MinHeap MinH = IniteMinHeap(capacity);
    int data;
    for (int i = 0; i < capacity; ++i)
    {
        cin >> data;
        InsertHeap(data, MinH);
    }
    return MinH;
}

void PrintHeap(const MinHeap &MinH, int routeNum = 1)
{
    int i;
    for (; routeNum > 0; --routeNum)
    {
        vector<int> result;
        cin >> i;
        for (; i > 0; i /= 2)
        {
            result.push_back(MinH->data[i]);
        }
        for (i = 0; i < result.size() - 1; ++i)
        {
            cout << result[i] << ' ';
        }
        cout << result[i] << endl;
    }
}

int main()
{
    int capacity, routeNum;
    cin >> capacity >> routeNum;
    MinHeap MinH = CreateHeap(capacity);
    PrintHeap(MinH, routeNum);
    return 0;
}