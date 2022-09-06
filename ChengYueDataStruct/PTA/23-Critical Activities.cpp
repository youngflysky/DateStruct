// TITLE:关键活动
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MaxSzie = 101;
const int INF = 0xfffff;

int Nv, Ne;
int G[MaxSzie][MaxSzie];
int InDegree[MaxSzie] = {0}; //记录入度
int ETime[MaxSzie] = {0};    //记录各节点最早发生时间

int OutDegree[MaxSzie] = {0}; //记录出度
int LTime[MaxSzie] = {0};     //记录各节点最迟发生时间

void IniteG()
{
    for (int i = 0; i < Nv; ++i)
    {
        for (int j = 0; j < Nv; ++j)
        {
            G[i][j] = -1;
        }
    }
}

void BuildGraph()
{
    int v, w, e;
    for (int i = 0; i < Ne; ++i)
    {
        cin >> v >> w >> e;
        G[v - 1][w - 1] = e;
        ++InDegree[w - 1];
        ++OutDegree[v - 1];
    }
}

int TopSort()
{
    queue<int> que;
    int cnt = 0;
    int v;
    for (int i = 0; i < Nv; ++i)
    {
        if (InDegree[i] == 0)
        {
            que.push(i);
        }
    }
    while (!que.empty())
    {
        v = que.front();
        ++cnt;
        que.pop();
        for (int w = 0; w < Nv; ++w)
        {
            if (G[v][w] != -1)
            {
                if (ETime[v] + G[v][w] > ETime[w])
                {
                    ETime[w] = ETime[v] + G[v][w];
                }
                if (--InDegree[w] == 0)
                {
                    que.push(w);
                }
            }
        }
    }
    if (cnt != Nv)
    {
        return -1;
    }
    int max = 0;
    for (int i = 0; i < Nv; ++i) // NOTE:终点的最早发生时间最大;
    {
        if (max < ETime[i])
        {
            max = ETime[i];
        }
    }
    cout << max << endl;
    return max;
}

void ReTopSort(int earliestTime)
{
    queue<int> que;
    int w;
    for (int i = 0; i < Nv; ++i)
    {
        if (OutDegree[i] == 0)
        {
            LTime[i] = earliestTime; // NOTE:出度为0的点即为终点，其最迟发生时间与最早发生时间相同;
            que.push(i);
        }
    }
    while (!que.empty())
    {
        w = que.front();
        que.pop();
        for (int v = 0; v < Nv; ++v)
        {
            if (G[v][w] != -1)
            {
                if (LTime[w] - G[v][w] < LTime[v])
                {
                    LTime[v] = LTime[w] - G[v][w];
                }
                if (--OutDegree[v] == 0)
                {
                    que.push(v);
                }
            }
        }
    }
}

void ActivityEdge() // NOTE:关键路径满足四个条件：
                    //路径起点最早和最迟发生时间相等;
                    //路径存在;
                    //路径终点的最早和最迟发生时间相等;
                    //路径权值等于路径终点与起点的差值
{

    for (int v = 0; v < Nv; ++v)
    {
        if (ETime[v] != LTime[v])
        {
            continue;
        }
        for (int w = Nv - 1; w >= 0; --w) // NOTE:从Nv-1开始寻找，体现与输入时顺序相反;
        {
            if (G[v][w] != -1 && ETime[w] == LTime[w] && (LTime[w] - LTime[v] == G[v][w]))
            {
                cout << v + 1 << "->" << w + 1 << endl;
            }
        }
    }
}

int main()
{
    cin >> Nv >> Ne;
    IniteG();
    BuildGraph();

    int earliestTime = TopSort();
    if (earliestTime == -1)
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < Nv; ++i)
    {
        LTime[i] = INF;
    }

    ReTopSort(earliestTime);

    ActivityEdge();

    return 0;
}
