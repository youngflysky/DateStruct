// TITLE:哈利波特的考试--Floyed算法，多源最短路径问题
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
const int INF = 0xffffff;

int Nv, Ne;
int G[MaxSzie][MaxSzie] = {0};

void BuildGraph()
{

    cin >> Nv >> Ne;
    for (int i = 0, v, w, val; i < Ne; ++i)
    {
        cin >> v >> w >> val;
        G[v - 1][w - 1] = G[w - 1][v - 1] = val;
    }
}

int Dist[MaxSzie][MaxSzie];
void Inite_dist() // NOTE:节点初始化是关键,到自身距离为0，没有路径为 INF;
{
    for (int i = 0; i < Nv; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (i == j)
            {
                Dist[i][j] = 0;
            }
            else if (G[i][j])
            {
                Dist[i][j] = Dist[j][i] = G[i][j];
            }
            else
            {
                Dist[i][j] = Dist[j][i] = INF;
            }
        }
    }
}

// READ:Floyed算法适合稠密图，稀疏图可以调用Nv-1次Dijkstra算法;
void Floyed() // READ:Floyed算法，多源最短路径算法，每一个节点的收录都会影响全局;
{
    Inite_dist();
    for (int k = 0; k < Nv; ++k) // READ:逐个收录节点;
    {
        for (int v = 0; v < Nv; ++v)
        {
            for (int w = 0; w < Nv; ++w)
            {
                if (Dist[v][w] > Dist[v][k] + Dist[k][w])
                {
                    Dist[v][w] = Dist[v][k] + Dist[k][w];
                }
            }
        }
    }
}

void SelectAnimal()
{
    Floyed();

    int index = -1, dist = INF;
    int tempDist;
    bool flag;
    for (int i = 0; i < Nv; ++i)
    {
        tempDist = 0, flag = true;
        for (int j = 0; j < Nv; ++j)
        {
            if (Dist[i][j] == INF)
            {
                flag = false;
                break;
            }
            if (Dist[i][j] > tempDist)
            {
                tempDist = Dist[i][j];
            }
        }
        if (flag && dist > tempDist)
        {
            dist = tempDist;
            index = i + 1;
        }
    }
    if (dist == INF)
    {
        cout << 0;
    }
    else
    {
        cout << index << ' ' << dist;
    }
}

int main()
{
    BuildGraph();
    SelectAnimal();
    return 0;
}