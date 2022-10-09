#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void GetNextVal(int nextval[], int N, string s)
{
    nextval[0] = 0;
    if (N < 2)
    {
        return;
    }
    for (int i = 0, j; i < N - 1; ++i)
    {
        j = i + 1;
        if (s[j] == s[nextval[i]])
        {
            nextval[j] = nextval[i] + 1;
        }
        else
        {
            nextval[j] = 0;
        }
    }
}

int KMP(string OriStr, string PatStr)
{
    int MaxSize = OriStr.length();
    int N = PatStr.length();
    if (N > MaxSize)
    {
        return -1;
    }
    int *nextval = (int *)malloc(sizeof(int) * N);

    GetNextVal(nextval, N, PatStr);

    for (int p = 0, i = 0;;)
    {
        for (; OriStr[p] == PatStr[i]; ++p, ++i)
        {
            if (p < MaxSize && i == N - 1)
            {
                return p + 1 - N;
            }
            else if (p == MaxSize - 1 && i < N - 1)
            {
                return -1;
            }
        }
        if (i)
        {
            i = nextval[i - 1];
        }
        else if (++p == MaxSize)
        {
            return -1;
        }
    }

    return 0;
}

int main()
{
    string OriStr;
    int N;
    cin >> OriStr >> N;
    vector<string> VecPatStr;
    for (int i = 0; i < N; ++i)
    {
        string temps;
        cin >> temps;
        VecPatStr.push_back(temps);
    }
    for (int i = 0; i < N; ++i)
    {
        string PatStr = VecPatStr[i];
        int flag = KMP(OriStr, PatStr);
        if (flag == -1)
        {
            cout << "Not Found" << endl;
        }
        else
        {
            string temps = OriStr.substr(flag);
            cout << temps << endl;
        }
    }

    return 0;
}