// TITLE:字符串匹配问题-KMP 算法
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int *GetNext(string T)
{
    int N = T.length();
    int *next = (int *)malloc(sizeof(int) * N);
    next[0] = 0;
    if (N < 2)
    {
        return next;
    }
    for (int i = 0, j; i < N - 1; ++i)
    {
        j = i + 1;
        if (T[j] == T[next[i]])
        {
            next[j] = next[i] + 1;
        }
        else
        {
            next[j] = 0;
        }
    }
    return next;
}

int KMP(string S, string T)
{
    int lenS = S.length();
    int lenT = T.length();
    int *next = GetNext(T);

    for (int p = 0, i = 0;;)
    {
        for (; S[p] == T[i]; ++p, ++i)
        {
            if (p < lenS && i == lenT - 1)
            {
                return p + 1 - lenT;
            }
            else if (p == lenS - 1 && i < lenT - 1)
            {
                return -1;
            }
        }
        if (i)
        {
            i = next[i - 1];
        }
        else if (++p == lenS)
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
        if (PatStr.length() > OriStr.length())
        {
            cout << "Not Found" << endl;
            continue;
        }
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