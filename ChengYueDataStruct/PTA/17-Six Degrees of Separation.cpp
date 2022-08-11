// TITLE:六度空间
#include <iomanip>
#include <iostream>
#include <queue>
using namespace std;
#define MAX 1005

int Nv, Ne;
int G[MAX][MAX] = {0};

int visited[MAX] = {0};
void RestoreVisited()
{
    for (int i = 1; i <= Nv; ++i)
    {
        visited[i] = 0;
    }
}

void BuildMGraph() //建图
{
    cin >> Nv >> Ne;
    int v, w;
    for (int i = 0; i < Ne; ++i)
    {
        cin >> v >> w;
        G[v][w] = G[w][v] = 1;
    }
}

int BFS(int v)
{
    queue<int> que;
    int count = 1;
    que.push(v);
    visited[v] = 1;
    int level = 0, last = v;
    int tail;

    while (!que.empty())
    {
        v = que.front();
        que.pop();
        for (int i = 1; i <= Nv; ++i)
        {
            if (visited[i] == 0 && G[v][i] == 1)
            {
                que.push(i);
                ++count;
                visited[i] = 1;
                tail = i;
            }
        }
        // NOTE:计算 BFS 层数
        if (last == v)
        {
            ++level;
            last = tail;
        }
        if (level == 6)
        {
            break;
        }
    }
    RestoreVisited();
    return count;
}

void Print()
{
    int count;
    for (int i = 1; i <= Nv; ++i)
    {
        count = BFS(i);
        cout << i << ": " << fixed << setprecision(2) << (double)count / Nv * 100 << '%' << endl;
    }
}

main()
{
    BuildMGraph();
    Print();
    return 0;
}