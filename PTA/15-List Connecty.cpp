// TITLE:列出连通集-图的DFS和BFS遍历方式
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

const int MaxSzie = 12;

int Nv, Ne;
int G[MaxSzie][MaxSzie] = {0};
bool Visited[MaxSzie] = {false};
void RestoreVisted()
{
    for (int i = 0; i < MaxSzie; ++i)
    {
        Visited[i] = false;
    }
}

void BuildGraph()
{
    cin >> Nv >> Ne;
    for (int p = 0, i, j; p < Ne; ++p)
    {
        cin >> i >> j;
        G[i][j] = G[j][i] = 1;
    }
}

void DFS(int v)
{
    cout << v << ' ';
    Visited[v] = true;
    for (int w = 0; w < Nv; ++w)
    {
        if (!Visited[w] && G[v][w])
        {
            DFS(w);
        }
    }
}

void Sol_DFS()
{
    RestoreVisted();
    for (int v = 0; v < Nv; ++v)
    {
        if (!Visited[v])
        {
            cout << "{ ";
            DFS(v);
            cout << '}' << endl;
        }
    }
}

void BFS(int v)
{
    queue<int> que;
    que.push(v);
    Visited[v] = true;
    while (!que.empty())
    {
        v = que.front(), que.pop();
        cout << v << ' ';
        for (int w = 0; w < Nv; ++w)
        {
            if (!Visited[w] && G[v][w])
            {
                que.push(w);
                Visited[w] = true; // NOTE:BFS在此处标记Visted[]数组;
            }
        }
    }
}

void Sol_BFS()
{
    RestoreVisted();
    for (int v = 0; v < Nv; ++v)
    {
        if (!Visited[v])
        {
            cout << "{ ";
            BFS(v);
            cout << '}' << endl;
        }
    }
}

int main()
{
    BuildGraph();
    Sol_DFS();
    Sol_BFS();
    return 0;
}