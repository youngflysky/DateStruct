#include <cstdlib>
#include <iostream>
using namespace std;
#define MAXN 100

// NOTE:邻接矩阵的节点定义
typedef struct
{
    int no; //顶点编号;
    // DataType data;存放节点中的信息
    char data;
} Vertex;
// NOTE:图的邻接矩阵定义
typedef struct MatGraph *Graph;
typedef struct MatGraph
{
    int edge[MAXN][MAXN]; //邻接矩阵定义；如果是有权图，定义为 float 型
    int n, e;
    Vertex vex[MAXN]; //存放节点信息;
} MatGraph;

Graph BuildGraph()
{
    Graph G = new MatGraph;
    int i, j, v1, v2, w;
    cin >> G->n;
    // 初始化图
    for (i = 0; i < G->n; ++i)
    {
        for (j = 0; j < G->n; ++j)
        {
            G->edge[i][j] = 0;
        }
    }
    cin >> G->e;
    // 插入边
    for (i = 0; i < G->e; i++)
    {
        cin >> v1 >> v2 >> w;
        G->edge[v1][v2] = w;
        G->edge[v2][v1] = w;
    }
    return G;
}

// 遍历图
void Print(const Graph G)
{
    int i, j;
    for (i = 0; i < G->n; i++)
    {
        for (j = 0; j < G->n; j++)
        {
            cout << G->vex[j].data;
        }
        cout << endl;
    }
}

int main()
{
    Graph G = BuildGraph();
    Print(G);
    return 0;
}
