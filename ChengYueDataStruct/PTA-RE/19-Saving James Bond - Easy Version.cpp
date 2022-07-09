// TITLE:Saving James Bond - Easy Version
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

#define maxSize 105
#define Radius 7.5

int Nv, Jump;
class Point
{
private:
    int x, y;

public:
    static int Jump;
    static void IniteJump(int J = 0)
    {
        Jump = J;
        return;
    }

public:
    Point() : x(0), y(0) {}
    ~Point() {}
    void GetPoint()
    {
        cin >> x >> y;
    }
    bool FirstJump()
    {
        if ((Jump + Radius) * (Jump + Radius) > x * x + y * y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool IsSafe()
    {
        if (Jump >= (50 - abs(x)) || Jump >= (50 - abs(y)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool CanJump(Point &p)
    {
        if (Jump * Jump >= pow(x - p.x, 2) + pow(y - p.y, 2))
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
Point Graph[maxSize];
int Visited[maxSize] = {0};

void BuildGraph()
{
    Point::IniteJump(Jump);
    for (int i = 0; i < Nv; ++i)
    {
        Graph[i].GetPoint();
    }
}

bool DFS(int n)
{
    Visited[n] = 1;
    if (Graph[n].IsSafe())
    {
        return true;
    }
    else
    {
        bool Safe = false;
        for (int i = 0; i < Nv && !Safe; ++i)
        {
            if (!Visited[i] && Graph[i].CanJump(Graph[n]))
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
        if (!Visited[i] && Graph[i].FirstJump())
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