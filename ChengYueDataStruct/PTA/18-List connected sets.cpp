// TITLE:列出连通集
#include <iostream>
#include <vector>
#define MaxSize 10
using namespace std;

typedef struct
{
    int edge[MaxSize][MaxSize] = {0};
    int Nv, Ne;
} MGraph, *PtrMGraph; // README:定义邻接矩阵;

PtrMGraph BuildGraph() // README:建图;
{
    PtrMGraph G = new MGraph;
    cin >> G->Nv >> G->Ne;
    // for (int i = 0; i < G->Nv; ++i)
    // {
    //     for (int j = 0; j < G->Nv; ++j)
    //     {
    //         G->edge[i][j] = 0;
    //     }
    // }
    for (int i = 0, m, n; i < G->Ne; ++i)
    {
        cin >> m >> n;
        G->edge[m][n] = G->edge[n][m] = 1;
    }
    return G;
}

vector<int> resultDFS;          // README:结果数组，暂存连通集各点;
void Print(vector<int> &result) // README:打印结果数组
{
    cout << "{ ";
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << ' ';
    }
    cout << '}' << endl;
    result.clear();
}

vector<int> visited;         // README:全局数组标志 G 是否被 DFS 访问过;
void DFS(PtrMGraph G, int v) // README:利用堆栈递归 DFS 访问图中的连通集
{
    resultDFS.push_back(v);
    visited[v] = 1;
    int i;
    for (i = 0; i < G->Nv; ++i)
    {
        if (G->edge[v][i] == 1 && visited[i] == 0)
        {
            DFS(G, i);
        }
    }
}

void ListConnectedSetsDFS(const PtrMGraph G) // README:列出 DFS 连通集;
{
    for (int i = 0; i < G->Nv; ++i)
    {
        visited.push_back(0);
    }
    for (int i = 0; i < G->Nv; ++i)
    {
        if (visited[i] == 0)
        {
            DFS(G, i);
            Print(resultDFS);
        }
    }
    visited.clear();
}

vector<int> resultBFS;
void BFS(PtrMGraph G, int v)
{
    resultBFS.push_back(v);
    visited[v] = 1;
    int que[MaxSize], front = 0, rear = 0;
    rear = (rear + 1) % MaxSize;
    que[rear] = v;
    int j;
    while (front != rear)
    {
        front = (front + 1) % MaxSize;
        j = que[front];
        for (int i = 0; i < G->Nv; ++i)
        {
            if (G->edge[j][i] == 1 && visited[i] == 0)
            {
                resultBFS.push_back(i);
                visited[i] = 1;
                rear = (rear + 1) % MaxSize;
                que[rear] = i;
            }
        }
    }
}

void ListConnectedSetsBFS(const PtrMGraph G)
{
    for (int i = 0; i < G->Nv; ++i)
    {
        visited.push_back(0);
    }
    for (int i = 0; i < G->Nv; ++i)
    {
        if (visited[i] == 0)
        {
            BFS(G, i);
            Print(resultBFS);
        }
    }
    visited.clear();
}

int main()
{
    PtrMGraph G = BuildGraph();
    ListConnectedSetsDFS(G);
    ListConnectedSetsBFS(G);
    return 0;
}