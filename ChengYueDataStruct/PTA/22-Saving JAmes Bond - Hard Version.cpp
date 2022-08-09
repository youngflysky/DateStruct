// TITLE:22-Saving JAmes Bond - Hard Version
#include <cmath>
#include <iostream>
#include <queue>
using namespace std;
#define MaxSize 101
#define DIAMETER 15
#define INF 101

int Nv, Jump;

typedef struct GraphNode
{
    int x, y;
    bool firstV, lastV;

    bool IsFirstV()
    {
        return x * x + y * y <= (Jump + DIAMETER / 2) * (Jump + DIAMETER / 2);
    }
    bool IsLastV()
    {
        return abs(x) + Jump >= 50 || abs(y) + Jump >= 50;
    }
} GraphNode;
GraphNode GNode[MaxSize];
int Dist[MaxSize], Path[MaxSize], Pre[MaxSize];

bool Cmp(int s1, int s2) //比较两个起点谁距离小岛更近;
{
    return GNode[s1].x * GNode[s1].x + GNode[s1].y * GNode[s1].y > GNode[s2].x * GNode[s2].x + GNode[s2].y * GNode[s2].y;
}
bool CanJump(int p1, int p2) //判断 James 是否可以从 P1 跳到 P2;
{
    return (GNode[p1].x - GNode[p2].x) * (GNode[p1].x - GNode[p2].x) + (GNode[p1].y - GNode[p2].y) * (GNode[p1].y - GNode[p2].y) <= Jump * Jump;
}
void IniteDist(int s) //初始化 Dist 数组, 到自身距离为0，到其他点距离为一个 特殊值（无法取到的值）;
{
    for (int i = 0; i < Nv; ++i)
    {
        Dist[i] = -1;
    }
    Dist[s] = 0;
}
void CopyPath() //将临时“路径数组 Pre 复制到 Path 中”;
{
    for (int i = 0; i < Nv; ++i)
    {
        Path[i] = Pre[i];
    }
}
void PrintPath(int s, int w) // NOTE:递归逆序打印 “路径数组”;
{
    if (s == w)
    {
        cout << GNode[s].x << ' ' << GNode[s].y << endl;
        return;
    }
    PrintPath(s, Path[w]);
    cout << GNode[w].x << ' ' << GNode[w].y << endl; // NOTE:当打印至于递归入口之前时则为顺序打印;
}

void BuildGraph()
{
    for (int i = 0; i < Nv; ++i)
    {
        cin >> GNode[i].x >> GNode[i].y;
        GNode[i].firstV = GNode[i].IsFirstV();
        GNode[i].lastV = GNode[i].IsLastV();
    }
}

void ShortestPath_UnweighedG(int s) // NOTE:无向无权图的单源最短路径算法;
{
    IniteDist(s);
    queue<int> que;
    que.push(s);
    int v;
    while (!que.empty())
    {
        v = que.front();
        que.pop();
        for (int w = 0; w < Nv; ++w)
        {
            if (Dist[w] == -1 && CanJump(v, w))
            {
                Dist[w] = Dist[v] + 1;
                Pre[w] = v;
                que.push(w);
            }
        }
    }
}

void Saving007()
{
    int minDist = INF; //记录最短路径
    int S, W;          // S--起点，W--终点;
    for (int s = 0; s < Nv; ++s)
    {
        if (!GNode[s].firstV)
        {
            continue;
        }
        ShortestPath_UnweighedG(s);

        for (int w = 0; w < Nv; ++w)
        {
            if (!GNode[w].lastV || Dist[w] == -1)
            {
                continue;
            }
            if (minDist > Dist[w])
            {
                minDist = Dist[w];
                S = s;
                W = w;
                CopyPath();
            }
            else if (minDist == Dist[w] && Cmp(S, s))
            {
                S = s;
                W = w;
                CopyPath();
            }
        }
    }

    if (minDist == INF)
    {
        cout << 0;
    }
    else
    {
        cout << Dist[W] + 2 << endl;
        PrintPath(S, W);
    }

    return;
}

int main()
{
    cin >> Nv >> Jump;
    BuildGraph();
    if (Jump + DIAMETER / 2 >= 50)
    {
        cout << 1;
        return 0;
    }
    Saving007();
    return 0;
}
