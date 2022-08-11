// TITLE:Complete Binary Seaarch Tree
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int N;

void InsertSort();

void GetSequence() //读入给定数列
{
    cin >> N;
    int data;
    for (int i = 0; i < N; ++i)
    {
        cin >> data;
        arr.push_back(data);
    }
    sort(arr.begin(), arr.end());
}

int GetLeftLength(int N)
{
    if (N == 1)
    {
        return 0;
    }
    int sum = 1;
    int level = 1;
    int i;
    for (i = 2; sum < N; ++i)
    {
        level *= 2;
        sum += level;
    }
    sum -= level;
    int plus = N - sum;
    sum = (sum - 1) / 2;
    int L_Level = level / 2;
    if (plus <= L_Level)
    {
        return sum + plus;
    }
    else
    {
        return sum + L_Level;
    }
}

void CreateCBT(int L, int R, int Root, vector<int> &CBT) //建立完全二叉排序树;
{
    if (L > R)
    {
        return;
    }
    int LengthL = GetLeftLength(R - L + 1);
    CBT[Root] = arr[L + LengthL];
    CreateCBT(L, L + LengthL - 1, 2 * Root + 1, CBT);
    CreateCBT(L + LengthL + 1, R, 2 * Root + 2, CBT);
    return;
}

void PrintCBT(const vector<int> &CBT)
{
    for (int i = 0; i < N - 1; ++i)
    {
        cout << CBT[i] << ' ';
    }
    cout << CBT[N - 1];
}

int main()
{
    GetSequence();
    vector<int> CBT(N);
    CreateCBT(0, N - 1, 0, CBT);
    PrintCBT(CBT);
    return 0;
}