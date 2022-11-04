// TITLE:关键活动--AOE网-关键路径问题;
// READ:关键路径问题需要对节点入度进行拓扑排序;同时对节点初读进行逆拓扑排序;
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

const int MaxSize = 105;
const int INF = 0xffffff;

int Nv, Ne;
int G[MaxSize][MaxSize];
int InDegree[MaxSize] = {0}, OutDegree[MaxSize] = {0};

void Inite_G()
{
    for (int i = 0; i < Nv; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            G[i][j] = G[j][i] = -1; // NOTE:求最短路径的图不允许出现负边的。但允许出现0边，故初始化为-1;
        }
    }
}
void BuildGraph()
{

    cin >> Nv >> Ne;
    Inite_G();
    int v, w, val;
    for (int i = 0; i < Ne; ++i)
    {
        cin >> v >> w >> val;
        G[v - 1][w - 1] = val;
        ++OutDegree[v - 1], ++InDegree[w - 1];
    }
}

int Dist[MaxSize], ReDist[MaxSize];
void Inite_Dist_Redist()
{
    for (int i = 0; i < Nv; ++i)
    {
        Dist[i] = 0, ReDist[i] = INF;
    }
}
void PrintCriPath()
{
    for (int v = 0; v < Nv; ++v)
    {
        if (Dist[v] == ReDist[v])
        {
            for (int w = Nv - 1; w >= 0; --w) // READ:体现与输入时顺序相反;
            {
                if (Dist[w] == ReDist[w] && G[v][w] != -1 && G[v][w] == Dist[w] - Dist[v])
                {
                    cout << v + 1 << "->" << w + 1 << endl;
                }
            }
        }
    }
}

int leastCost = 0;
bool TopSort()
{
    queue<int> que;
    for (int i = 0; i < Nv; ++i)
    {
        if (!InDegree[i])
        {
            que.push(i);
            Dist[i] = 0;
        }
    }
    int count = 0;
    int v;
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
    if (count != Nv)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < Nv; ++i)
        {
            if (leastCost < Dist[i])
            {
                leastCost = Dist[i];
            }
        }
        return true;
    }
}

void ReTopSort()
{
    queue<int> que;
    for (int i = 0; i < Nv; ++i)
    {
        if (!OutDegree[i])
        {
            que.push(i);
            ReDist[i] = leastCost; // NOTE:所有终点的ReDist都要被初始化成最大的Dist,即最短完成时间是唯一的;
        }
    }

    int w;
    while (!que.empty())
    {
        w = que.front(), que.pop();

        for (int v = 0; v < Nv; ++v)
        {
            if (G[v][w] != -1)
            {
                if (ReDist[v] > ReDist[w] - G[v][w])
                {
                    ReDist[v] = ReDist[w] - G[v][w];
                }
                if (--OutDegree[v] == 0)
                {
                    que.push(v);
                }
            }
        }
    }
}

void Solution()
{
    Inite_Dist_Redist();
    if (TopSort())
    {
        ReTopSort();
        cout << leastCost << endl;
        PrintCriPath();
    }
    else
    {
        cout << 0;
    }
}

int main()
{
    BuildGraph();
    Solution();
    return 0;
}