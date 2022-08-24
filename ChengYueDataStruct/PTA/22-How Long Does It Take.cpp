// TITLE:How Long Does It Take
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int MaxSzie = 101;

int Nv, Ne;
int G[MaxSzie][MaxSzie];
int Dist[MaxSzie] = {0};
int InDegree[MaxSzie] = {0};

void IniteG()
{
    for (int i = 0; i < Nv; ++i)
    {
        for (int j = 0; j < Nv; ++j)
        {
            G[i][j] = -1;
        }
    }
}

void BuildGraph()
{
    int v, w, e;
    for (int i = 0; i < Ne; ++i)
    {
        cin >> v >> w >> e;
        G[v][w] = e;
        ++InDegree[w];
    }
}

void TopSort()
{
    queue<int> que;
    int cnt = 0;
    int longestTime = 0;
    int v;
    for (int i = 0; i < Nv; ++i)
    {
        if (InDegree[i] == 0)
        {
            que.push(i);
        }
    }
    while (!que.empty())
    {
        v = que.front();
        ++cnt;
        que.pop();
        for (int w = 0; w < Nv; ++w)
        {
            if (G[v][w] != -1)
            {
                if (Dist[v] + G[v][w] > Dist[w])
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
    sort(Dist, Dist + Nv);
    if (cnt != Nv)
    {
        cout << "Impossible";
    }
    else
    {
        cout << Dist[Nv - 1];
    }
}

int main()
{
    cin >> Nv >> Ne;
    IniteG();
    BuildGraph();
    TopSort();
    return 0;
}