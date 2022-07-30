#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MaxSize 105
#define RADIUS 7.5
#define INF 105

int Nv, Jump;

class Point
{
private:
    static int Jump;

public:
    static void IniteJump(int parameter = 0)
    {
        Jump = parameter;
        return;
    }

public:
    int x, y;

    int Distance_Origin()
    {
        return x * x + y * y;
    }

public:
    int dist[MaxSize];
    int path[MaxSize] = {0};

public:
    Point() : x(0), y(0){};
    ~Point(){};

    void InputPoint()
    {
        cin >> x >> y;
        if (x * x >= 50 * 50 || y * y >= 50 * 50 || (x * x + y * y) < RADIUS * RADIUS)
        {
            x = y = INF;
        }
        return;
    }

    bool IsFirstV()
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

    void IniteDist(int s)
    {

        for (int i = 0; i < Nv; ++i)
        {
            dist[i] = -1;
        }
        dist[s] = 1;
    }

    bool ExistEdge(Point &i)
    {
        if (pow(i.x - x, 2) + pow(i.y - y, 2) < pow(Jump, 2))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool JumpBank()
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

    void FindPath(int initeV, int lastV, vector<int> &result)
    {
        if (path[lastV] == initeV)
        {
            result.push_back(lastV);
            result.push_back(initeV);
            return;
        }
        else
        {
            result.push_back(lastV);
            lastV = path[lastV];
            FindPath(initeV, lastV, result);
        }
    }
};
int Point::Jump = 0;
Point G[MaxSize];

void BuildGraph()
{
    cin >> Nv >> Jump;
    Point::IniteJump(Jump);
    for (int i = 0; i < Nv; ++i)
    {
        G[i].InputPoint();
    }
}

int MinDist_UnweighedG(int s, int &lastV);

void SavingJames()
{
    int minDist = INF, initeV = 0, lastV = 0;
    int tempDist, tempLastV;
    for (int i = 0; i < Nv; ++i)
    {
        if (!G[i].IsFirstV())
        {
            continue;
        }
        tempDist = MinDist_UnweighedG(i, tempLastV);
        if (tempDist == INF)
        {
            continue;
        }
        else if (minDist > tempDist)
        {
            minDist = tempDist;
            initeV = i;
            lastV = tempLastV;
        }
        else if (minDist == tempDist)
        {
            if (G[initeV].Distance_Origin() > G[i].Distance_Origin())
            {
                initeV = i;
                lastV = tempLastV;
            }
        }
    }
    if (minDist == INF)
    {
        cout << '0' << endl;
    }
    else
    {
        cout << minDist << endl;
        vector<int> result;
        G[initeV].FindPath(initeV, lastV, result);
        for (int i = result.size() - 1; i >= 0; --i)
        {
            cout << G[result[i]].x << ' ' << G[result[i]].y << endl;
        }
    }
}

int MinDist_UnweighedG(int s, int &tempLastV)
{
    G[s].IniteDist(s);
    queue<int> que;
    int v_ing;
    que.push(s);
    while (!que.empty())
    {
        v_ing = que.front();
        if (G[v_ing].JumpBank())
        {
            tempLastV = v_ing;
            return G[s].dist[v_ing] + 1;
            break;
        }
        que.pop();
        for (int w = 0; w < Nv; ++w)
        {
            if (G[s].dist[w] == -1 && G[v_ing].ExistEdge(G[w]))
            {
                G[s].dist[w] = G[s].dist[v_ing] + 1;
                G[s].path[w] = v_ing;
                que.push(w);
            }
        }
    }
    return INF;
}

int main()
{
    BuildGraph();
    if (Jump + RADIUS >= 50)
    {
        cout << "1" << endl;
        return 0;
    }
    SavingJames();
    return 0;
}