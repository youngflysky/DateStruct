// TITLE:公路村村通
#include <iostream>
using namespace std;

#define MaxSize 1005
#define INF 0xfffff

int Nv, Ne;
int G[MaxSize][MaxSize];
int Dist[MaxSize];
bool Collected[MaxSize] = {false};

void IniteGraph()
{
    for (int i = 0; i < Nv; ++i)
    {
        for (int j = 0; j < Nv; ++j)
        {
            G[i][j] = INF;
        }
    }
}
void BuildGraph()
{
    cin >> Nv >> Ne;
    IniteGraph();
    for (int i = 0, x, y, e; i < Ne; ++i)
    {
        cin >> x >> y >> e;
        --x, --y;
        G[x][y] = G[y][x] = e;
    }
    return;
}

int Prim(int s = 0)
{
    for (int i = 0; i < Nv; ++i)
    {
        Dist[i] = G[s][i]; // NOTE:与Dijkstra中Dist[]的初始化不同;
    }
    Collected[s] = true;
    int minDist, i, v, sum = 0;
    for (i = 0; i < Nv - 1; ++i) // NOTE:循环次数不同;少一次;
    {
        minDist = INF, v = -1;
        for (int j = 0; j < Nv; ++j)
        {
            if (!Collected[j] && minDist > Dist[j])
            {
                minDist = Dist[j];
                v = j;
            }
        }
        if (v == -1)
        {
            break;
        }
        Collected[v] = true;
        sum += minDist;
        for (int w = 0; w < Nv; ++w)
        {
            if (!Collected[w] && G[v][w] < Dist[w]) // NOTE:调整方式不同;
            {
                Dist[w] = G[v][w];
            }
        }
    }
    if (i != Nv - 1)
    {
        return -1;
    }
    return sum;
}

int main()
{
    BuildGraph();
    cout << Prim();

    return 0;
}