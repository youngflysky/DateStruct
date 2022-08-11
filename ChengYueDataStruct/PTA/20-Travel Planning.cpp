// TITLE:旅游规划
#include <iostream>
using namespace std;
#define MaxSize 501
#define INF 0xfffff

typedef struct Edge
{
    int dist = INF;
    int price;
} GraphNode;
int N, M, S, D;
GraphNode G[MaxSize][MaxSize];
GraphNode Dist[MaxSize]; // NOTE:DS 类型定义为边，下标定义为点;
int Collected[MaxSize] = {0};

void BuildGraph()
{
    int p1, p2, d, p;
    for (int i = 0; i < M; ++i)
    {
        cin >> p1 >> p2 >> d >> p;
        G[p1][p2].dist = G[p2][p1].dist = d;
        G[p1][p2].price = G[p2][p1].price = p;
    }
    return;
}

void Dijkstra()
{
    Dist[S].dist = 0;

    int v;
    int minD;
    while (true)
    {
        minD = INF, v = -1;
        for (int i = 0; i < N; ++i) // v=未收录顶点中Dist最小者
        {
            if (!Collected[i])
            {
                if (minD > Dist[i].dist) // NOTE:以距离作主权值;
                {
                    minD = Dist[i].dist;
                    v = i;
                }
            }
        }
        if (v == -1) //如果这样的v不存在则结束;
        {
            break;
        }
        Collected[v] = 1;
        for (int w = 0; w < N; ++w) //对v的每个邻接点W;
        {
            if (!Collected[w])
            {
                if (Dist[v].dist + G[v][w].dist < Dist[w].dist)
                {
                    Dist[w].dist = Dist[v].dist + G[v][w].dist;
                    Dist[w].price = Dist[v].price + G[v][w].price;
                }
                // NOTE:往下多层嵌套作副权值;
                if (Dist[v].dist + G[v][w].dist == Dist[w].dist && Dist[v].price + G[v][w].price < Dist[w].price)
                {
                    Dist[w].price = Dist[v].price + G[v][w].price;
                }
            }
        }
    };
    cout << Dist[D].dist << ' ' << Dist[D].price << endl;
    return;
}

int main()
{
    cin >> N >> M >> S >> D;
    BuildGraph();
    Dijkstra();
    return 0;
}