// DFS Graph
#include <iostream>
#include <vector>
using namespace std;
#define MaxSize 100

typedef struct ArcNode //邻接表每个节点定义的是点;
{
    int adjV; //邻接节点编号;
    struct ArcNode *next;
} ArcNode;

typedef struct //图的顶点定义;
{
    char data; //顶点信息;
    ArcNode *first;
} VNode;

typedef struct
{
    VNode adjlist[MaxSize];
    int n, e;
} AGraph;
vector<int> visited(MaxSize); //访问标记

//深度优先搜索遍历,使用邻接表为存储结构(递归)
void DFS(AGraph *G, int v) // README:类似于 树 的先序遍历;
{
    // Visit(v);
    visited[v] = 1;
    ArcNode *p;
    p = G->adjlist[v].first; //指向第一条边
    while (p != NULL)
    {
        if (visited[p->adjV] == 0) //若顶点未被访问,则递归
            DFS(G, p->adjV);
        p = p->next;
    }
}
void BFS(AGraph *G, int v)
{
    // visit(v);
    visited[v] = 1;
    int que[MaxSize], front = 0, rear = 0;
    rear = (rear + 1) % MaxSize;
    que[rear] = v;
    int j;
    ArcNode *p;
    while (rear != front)
    {
        front = (front + 1) % MaxSize;
        j = que[front];
        p = G->adjlist[j].first;
        while (p)
        {
            if (visited[p->adjV] == 0)
            {
                // visit(p->adjV);
                visited[p->adjV] = 1;
                rear = (rear + 1) % MaxSize;
                que[rear] = p->adjV;
            }
            p = p->next;
        }
    }
}

int main()
{

    return 0;
}