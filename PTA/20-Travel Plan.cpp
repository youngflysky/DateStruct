// TITLE:旅游规划--Dijkstra 算法;
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

const int MaxSzie = 505;
const int INF = 0XFFFFFF;

int Nv, Ne;
int S, D;

typedef struct GraphVal
{
    int dist;
    int price;
    GraphVal() : dist(INF), price(INF) {}
} GraphVal;
GraphVal G[MaxSzie][MaxSzie]; // README:矩阵的一对坐标队定位一条边;

int Dist[MaxSzie], Price[MaxSzie];
bool collected[MaxSzie];
void Inite_dist_path_collected()
{
    for (int i = 0; i < Nv; ++i)
    {
        Dist[i] = Price[i] = INF;

        collected[i] = false;
    }
}

void BuildGraph()
{
    cin >> Nv >> Ne >> S >> D;
    for (int i = 0, v, w, d, p; i < Ne; ++i)
    {
        cin >> v >> w >> d >> p;
        G[w][v].dist = G[v][w].dist = d, G[w][v].price = G[v][w].price = p;
    }
}

void Dijkstra(int s) // NOTE:Dijkstra:单源有权图最短路径算法;
{
    Inite_dist_path_collected();

    Dist[s] = 0;  // NOTE:主权;
    Price[s] = 0; // NOTE:副权

    int minE;
    int v;
    while (true)
    {
        minE = INF;
        for (int i = 0; i < Nv; ++i)
        {
            if (!collected[i] && Dist[i] < minE)
            {
                minE = Dist[i];
                v = i;
            }
        }
        if (minE == INF) // README:未收集节点中没有最小dist时，即为结束条件;
        {
            return;
        }
        collected[v] = true;

        for (int w = 0; w < Nv; ++w)
        {
            if (!collected[w] && G[v][w].dist < INF)
            {
                if (Dist[w] > Dist[v] + G[v][w].dist)
                {
                    Dist[w] = Dist[v] + G[v][w].dist;
                    Price[w] = Price[v] + G[v][w].price;
                }
                else if (Dist[w] == Dist[v] + G[v][w].dist && Price[w] > Price[v] + G[v][w].price)
                {
                    Price[w] = Price[v] + G[v][w].price;
                }
            }
        }
    }
}

void TravelPlan()
{
    Dijkstra(S);
    cout << Dist[D] << ' ' << Price[D];
}

int main()
{
    BuildGraph();
    TravelPlan();
    return 0;
}