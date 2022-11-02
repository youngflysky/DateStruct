// TITLE:公路村村通--最小生成树问题--2-Kruskal算法--以边为核心，适合稀疏图;
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
typedef struct GraphEdge
{
    int v, w;
    int val;
} GraphEdge;
GraphEdge Road[3 * MaxSize];

void BuildGraph()
{
    cin >> Nv >> Ne;
    for (int i = 0; i < Ne; ++i)
    {
        cin >> Road[i].v >> Road[i].w >> Road[i].val;
    }
    return;
}

int Parent[MaxSize]; // NOTE:定义并查集数组;
void Inite_Parent()
{
    for (int i = 0; i < Nv; ++i)
    {
        Parent[i] = -1;
    }
}

int GetRoot(int v)
{
    while (Parent[v] != -1)
    {
        v = Parent[v];
    }
    return v;
}

bool Cmp(GraphEdge a, GraphEdge b)
{
    return a.val < b.val;
}

int Kruskal(int s = 0)
{
    Inite_Parent();
    sort(Road, Road + Ne, Cmp); // READ:先对所有边排序;
    int minDist, leastCost = 0;
    int R1, R2;
    int count = 0;
    for (int i = 0; i < Ne; ++i)
    {
        R1 = GetRoot(Road[i].v), R2 = GetRoot(Road[i].w); // NOTE:逐个收录不形成环路的最小的边;
        if (R1 != R2)
        {
            Parent[R2] = R1;
            leastCost += Road[i].val;
            ++count;
        }
    }
    if (count == Nv - 1)
    {
        return leastCost;
    }
    else
    {
        return -1;
    }
}

void LeastCost()
{
    cout << Kruskal();
}

int main()
{
    BuildGraph();
    LeastCost();

    return 0;
}