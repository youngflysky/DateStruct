// TITLE:公路村村通--最小生成树问题--1-Prime算法--以点为核心，适合稠密图;
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

const int MaxSize = 1001;
const int INF = 0xffffff;

int Nv, Ne;
int G[MaxSize][MaxSize] = {0};

void BuildGraph()
{
    cin >> Nv >> Ne;
    int v, w, val;
    for (int i = 0; i < Ne; ++i)
    {
        cin >> v >> w >> val;
        G[v - 1][w - 1] = G[w - 1][v - 1] = val;
    }
}

int leastCost = 0;
int Dist[MaxSize];
void Inite_MST_Dist()
{
    for (int i = 0; i < Nv; ++i)
    {

        Dist[i] = INF;
    }
}

bool Prime(int Root)
{
    Inite_MST_Dist();
    Dist[Root] = 0;

    int minDist, v;
    int count = 0;
    while (true)
    {
        minDist = INF;
        for (int i = 0; i < Nv; ++i)
        {
            if (Dist[i] != -1 && Dist[i] < minDist)
            {
                minDist = Dist[i];
                v = i;
            }
        }
        if (minDist == INF)
        {
            break;
        }
        Dist[v] = -1;         // NOTE:Dist[v]=-1,标记V已被收录;Dist[v]=0标记了起点Root,也是根节点;
        leastCost += minDist; // READ:每个合格的minDist都是一条最小生成边;
        ++count;

        for (int w = 0; w < Nv; ++w)
        {
            if (Dist[w] != -1 && G[v][w]) // READ:找出V的所有未被收录的邻接节点;
            {
                if (G[v][w] < Dist[w]) // NOTE:储存所有未收录节点和已收录节点中最小的邻边;
                {
                    Dist[w] = G[v][w];
                }
            }
        }
    }
    if (count == Nv)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void LeastCost()
{

    if (Prime(0))
    {
        cout << leastCost;
    }
    else
    {
        cout << -1;
        return;
    }
}

int main()
{
    BuildGraph();
    LeastCost();
    return 0;
}
