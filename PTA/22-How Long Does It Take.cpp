// TITLE:How Long Does It Take--AOV网-拓扑排序;
// READ:拓扑排序的图是AOV网,属于有向无环图;拓扑排序是关键路径问题的基础;
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

const int MaxSzie = 105;

int Nv, Ne;
int G[MaxSzie][MaxSzie];
int InDegree[MaxSzie] = {0}; // NOTE:拓扑排序需要存储边和入度两种信息;

void BuildGraph()
{
    cin >> Nv >> Ne;
    for (int i = 0; i < Nv; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            G[i][j] = G[j][i] = -1;
        }
    }
    int v, w, val;
    for (int i = 0; i < Ne; ++i)
    {
        cin >> v >> w >> val;
        G[v][w] = val;
        ++InDegree[w];
    }
}

void TopSort()
{
    int Dist[MaxSzie] = {0};
    queue<int> que;
    for (int i = 0; i < Nv; ++i)
    {
        if (!InDegree[i])
        {
            que.push(i);
        }
    }
    int v;
    int count = 0;
    while (!que.empty())
    {
        v = que.front(), que.pop();
        ++count;

        for (int w = 0; w < Nv; ++w)
        {
            if (G[v][w] != -1)
            {
                if (Dist[w] < Dist[v] + G[v][w])
                {
                    Dist[w] = Dist[v] + G[v][w];
                }
                if (--InDegree[w] == 0)
                {
                    que.push(w);
                }
            }
        }
    }
    if (count == Nv) // NOTE:此条件用来判断图中是否有环路;
    {
        int longDist = 0;
        for (int i = 0; i < Nv; ++i)
        {
            if (Dist[i] > longDist)
            {
                longDist = Dist[i];
            }
        }
        cout << longDist;
    }
    else
    {
        cout << "Impossible";
    }
}

int main()
{
    BuildGraph();
    TopSort();
    return 0;
}