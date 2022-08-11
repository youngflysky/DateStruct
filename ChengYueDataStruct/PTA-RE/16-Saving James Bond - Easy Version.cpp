// TITLE:Saving James Bond - Easy Version
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

#define maxSize 105
#define Radius 7.5

int Nv, Jump;
typedef struct GraphNode
{

    int x, y;
    bool isFirstV, isLastV;
    bool IsFirstV()
    {
        return (Jump + Radius) * (Jump + Radius) >= x * x + y * y;
    }
    bool IsLastV()
    {
        return abs(x) + Jump >= 50 || abs(y) + Jump >= 50;
    }
    bool IniteV()
    {
        cin >> x >> y;
        isFirstV = IsFirstV();
        isLastV = IsLastV();
    }
} GraphNode;
GraphNode GNode[maxSize];
int Visited[maxSize] = {0};

bool CanJump(int p1, int p2) //判断 James 是否可以从 P1 跳到 P2;
{
    return (GNode[p1].x - GNode[p2].x) * (GNode[p1].x - GNode[p2].x) + (GNode[p1].y - GNode[p2].y) * (GNode[p1].y - GNode[p2].y) <= Jump * Jump;
}

void BuildGraph()
{
    for (int i = 0; i < Nv; ++i)
    {
        GNode[i].IniteV();
    }
}

bool DFS(int n)
{
    Visited[n] = 1;
    if (GNode[n].isLastV)
    {
        return true;
    }
    else
    {
        bool Safe = false;
        for (int i = 0; i < Nv && !Safe; ++i)
        {
            if (!Visited[i] && CanJump(n, i))
            {
                Safe = DFS(i);
            }
        }
        return Safe;
    }
}

bool Save007()
{
    bool Safe = false;
    for (int i = 0; i < Nv && !Safe; ++i)
    {
        if (!Visited[i] && GNode[i].isFirstV)
        {
            Safe = DFS(i);
        }
    }
    return Safe;
}

int main()
{
    cin >> Nv >> Jump;
    BuildGraph();
    if (Jump > 50 - Radius)
    {
        cout << "Yes" << endl;
        return 0;
    }
    else
    {
        if (Save007())
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }

        return 0;
    }
}