// TITLE:Saving James Bond - Easy Version
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
#define MaxSize 105
#define RADIUS 7.5
#define DISTANCE 42.5

int Nv, Jump;
class Point
{
private:
    static int Jump; //类的静态函数成员赋予所有对象共享 Jump 这一数据;

public:
    static void IniteJump(int j)
    {
        Jump = j;
    }

private:
    int x, y;

public:
    Point() : x(0), y(0) {}
    void GetPoint(int i = 0) //读入顶点的信息;
    {
        cin >> x >> y;
    }
    bool IsSafe(int Jump) //该点是否能够跳到岸上;
    {
        if (x + Jump >= 50 || x - Jump <= -50 || y + Jump >= 50 || y - Jump <= -50)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool CanJump(Point &p) //判断某点是否是该点的邻边;
    {
        if (((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y)) <= Jump * Jump)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool FirstJump()
    {

        if ((RADIUS + Jump) * (RADIUS + Jump) >= (x * x + y * y))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int Point::Jump = 0;
Point Graph[MaxSize];

int visited[MaxSize] = {0};
void BuildGraph() //建图;
{
    Point::IniteJump(Jump);
    for (int i = 0; i < Nv; ++i)
    {
        Graph[i].GetPoint(i);
    }

    return;
}

bool DFS(int n)
{
    visited[n] = 1;
    if (Graph[n].IsSafe(Jump)) //该点能跳到岸上时，直接返回 true,结束;
    {
        return true;
    }
    else //该点不能跳到岸上时,
    {
        int i;
        bool Safe = false;

        for (int i = 0; i < Nv && !Safe; ++i)
        {
            // NOTE:所谓边实际上是两点间是否存在某种关系或者满足某种条件
            if (visited[i] == 0 && Graph[n].CanJump(Graph[i])) //递归返回该点所有邻接点结果;
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
        if (visited[i] == 0 && Graph[i].FirstJump())
        {
            Safe = DFS(i);
        }
    }
    return Safe;
}
int main()
{
    cin >> Nv >> Jump;
    if (Jump >= DISTANCE)
    {
        cout << "Yes"; //如果能够直接跳到岸上，则直接结束;
        return 0;
    }
    BuildGraph();
    if (Save007())
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}