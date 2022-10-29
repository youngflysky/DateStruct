// TITLE:Saving James Bond - Hard Version-单源无权最短路径算法;
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

int N, Jump;

class Crocodile
{
public:
    int x, y;
    void GetPos()
    {
        cin >> x >> y;
    }
    bool IsFirstV()
    {
        return x * x + y * y <= (7.5 + Jump) * (7.5 + Jump) && x * x + y * y >= 7.5 * 7.5;
    }
    bool CanEscape()
    {
        return (x + Jump >= 50) || (x - Jump <= -50) || (y + Jump >= 50) || (y - Jump <= -50);
    }
};

Crocodile G[MaxSize];
void BuildGraph()
{
    for (int i = 0; i < N; ++i)
    {
        G[i].GetPos();
    }
}

int dist[MaxSize], path[MaxSize] = {0}, pre[MaxSize] = {0}; //分别存储距离，路径，和临时路径;
void ResDit_Pre()                                           //初始化 dist[] & pre;
{
    for (int i = 0; i < N; ++i)
    {
        dist[i] = pre[i] = -1;
    }
}
void PrintPath(int v) //递归打印路径;
{
    if (v == -1)
    {
        return;
    }
    PrintPath(path[v]);
    cout << endl
         << G[v].x << ' ' << G[v].y;
}

bool CanJump(int v, int w) // NOTE:可以从v跳到w，即 v,w 存在边;图中两点之间符合某种约束就是抽象的边;
{
    return (G[v].x - G[w].x) * (G[v].x - G[w].x) + (G[v].y - G[w].y) * (G[v].y - G[w].y) <= Jump * Jump;
}

bool Cmp(int s1, int s2) // READ:默认 s1<s2 为真;
{
    return G[s1].x * G[s1].x + G[s1].y * G[s1].y < G[s2].x * G[s2].x + G[s2].y * G[s2].y;
}

void SinSouShortPath(int v)
{
    queue<int> que;
    que.push(v);
    dist[v] = 2;
    while (!que.empty())
    {
        v = que.front(), que.pop();
        for (int w = 0; w < N; ++w)
        {
            if (dist[w] == -1 && CanJump(v, w)) // READ:w 未被访问且 v&w 存在边;
            {
                dist[w] = dist[v] + 1;
                pre[w] = v;
                que.push(w);
            }
        }
    }
}

void Save007()
{
    int minD = INF;
    int S, W; //起点,终点;

    for (int s = 0; s < N; ++s)
    {
        if (!G[s].IsFirstV()) // NOTE:筛选出所有符合条件的连通子图的源节点;
        {
            continue;
        }
        if (G[s].CanEscape())
        {
            cout << 2 << endl
                 << G[s].x << ' ' << G[s].y;
            return;
        }

        ResDit_Pre();       // READ:最短路径算法启用之前要初始化 dist[] & pre 数组;
        SinSouShortPath(s); // NOTE:单源无权最短路径算法,只对连通图有效;
                            // NOTE:要计算出所有节点距源节点的最短路径;

        for (int w = 0; w < N; ++w)
        {
            if (dist[w] == -1 || !G[w].CanEscape())
            {
                continue;
            }
            if (dist[w] < minD)
            {
                minD = dist[w];
                S = s, W = w;
                for (int i = 0; i < N; ++i)
                {
                    path[i] = pre[i];
                }
            }
            else if (dist[w] == minD && Cmp(s, S)) // READ:同最短路径,选择第一个落点距小岛更近的;
            {
                S = s;
                W = w;
                for (int i = 0; i < N; ++i)
                {
                    path[i] = pre[i];
                }
            }
        }
    }
    if (minD == INF)
    {
        cout << 0;
    }
    else
    {
        cout << minD;
        PrintPath(W);
    }
}

int main()
{
    cin >> N >> Jump;
    if (Jump >= 42.5)
    {
        cout << 1;
        return 0;
    }

    BuildGraph();
    Save007();

    return 0;
}