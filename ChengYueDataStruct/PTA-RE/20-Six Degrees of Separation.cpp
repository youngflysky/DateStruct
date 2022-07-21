// TITLE:六度空间
#include <iomanip>
#include <iostream>
#include <queue>
using namespace std;
#define MaxSize 1005

void BuildGraph();     //建图
void PrintResult();    //输出每个节点符合条件的结果
int BFS(int v);        //层次遍历每个节点
void RestoreVisited(); //遍历完每个点后重置Visited;

int Nv, Ne;
int G[MaxSize][MaxSize] = {0};
int Visited[MaxSize] = {0};
void RestoreVisited()
{
    for (int v = 1; v <= Nv; ++v)
    {
        Visited[v] = 0;
    }
    return;
}

void BuildGraph()
{
    cin >> Nv >> Ne;
    int v, w;
    for (int i = 0; i < Ne; ++i)
    {
        cin >> v >> w;
        G[v][w] = G[w][v] = 1;
    }
    return;
}
void PrintResult()
{
    int count = 0;
    for (int i = 1; i <= Nv; ++i)
    {
        count = BFS(i);
        cout << i << ": " << fixed << setprecision(2) << (double)count / Nv * 100 << '%' << endl;
    }
}

int BFS(int v)
{
    Visited[v] = 1;
    int count = 1; //计数
    int level = 0; //记层
    int last = v;  //标记本层的最后一个节点
    int tail = 0;  //标记下一层最后一个节点

    queue<int> que;
    que.push(v);
    while (!que.empty())
    {
        v = que.front();
        que.pop();
        for (int i = 1; i <= Nv; ++i)
        {
            if (!Visited[i] && G[i][v] == 1)
            {
                Visited[i] = 1;
                ++count;
                que.push(i);
                tail = i;
            }
        }

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

int main()
{
    BuildGraph();
    PrintResult();

    return 0;
}