// TITLE:公路村村通
// NOTE:该图为稀疏图，使用 Kruskal Algorithm 效率更高;
#include <algorithm>
#include <iostream>
using namespace std;

#define MaxSize 1005
#define INF 0xfffff

int Nv, Ne;
typedef struct GraphEdge
{
    int x, y;
    int w;
} GraphEdge;
GraphEdge Road[3 * MaxSize];

int V[MaxSize]; // NOTE:定义并查集数组;

void BuildGraph()
{
    cin >> Nv >> Ne;
    for (int i = 0; i < Ne; ++i)
    {
        cin >> Road[i].x >> Road[i].y >> Road[i].w;
    }
    return;
}

void IniteV()
{
    for (int i = 0; i < Nv; ++i)
    {
        V[i] = -1;
    }
}

int GetRoot(int v)
{
    while (V[v] != -1)
    {
        v = V[v];
    }
    return v;
}

bool Cmp(GraphEdge a, GraphEdge b)
{
    return a.w < b.w;
}

int Kruskal(int s = 0)
{
    IniteV();
    sort(Road, Road + Ne, Cmp);
    int minDist, sum = 0;
    int a, b;
    int allEdges = 0;
    for (int i = 0; i < Ne; ++i)
    {
        a = GetRoot(Road[i].x), b = GetRoot(Road[i].y);
        if (a != b)
        {
            V[a] = b;
            sum += Road[i].w;
            ++allEdges;
        }
    }
    if (allEdges == Nv - 1)
    {
        return sum;
    }
    else
    {
        return -1;
    }
}

int main()
{
    BuildGraph();
    cout << Kruskal();

    return 0;
}