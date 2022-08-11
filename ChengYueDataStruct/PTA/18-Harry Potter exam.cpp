// TITLE:哈利·波特的考试
#include <iostream>
using namespace std;
#define INFINITY 10005 // NOTE:INIFINTY 最大值是 1w 不是 100
#define MaxSize 105

class Graph
{
private:
    int Nv, Ne;
    int G[MaxSize][MaxSize] = {0}; // NOTE: 初始化后的 Dist 只是 G 的一个副本，如果 G 不重用，则可以直接使用 G;
    typedef struct Animal_Length
    {
        int animal = 1;
        int length = INFINITY;
    } Animal_Length;
    Animal_Length minAnimal;

private:
    int FindMaxdist(int N)
    {
        int dist = 0;
        for (int i = 1; i <= Nv; ++i)
        {
            if (dist <= G[N][i])
            {
                dist = G[N][i];
            }
        }
        return dist;
    }

public:
    void BuildGraph()
    {
        cin >> Nv >> Ne;
        for (int i = 1; i <= Nv; ++i)
        {
            for (int j = 1; j <= Nv; ++j)
            {
                if (i != j)
                {
                    G[i][j] = INFINITY;
                }
            }
        }

        for (int i = 0, Ni, Nj, Nl; i < Ne; ++i)
        {
            cin >> Ni >> Nj >> Nl;
            G[Ni][Nj] = G[Nj][Ni] = Nl;
        }
    }

    void Floyd()
    {
        for (int k = 1; k <= Nv; ++k)
        {
            for (int i = 1; i <= Nv; ++i)
            {
                for (int j = 1; j <= Nv; ++j)
                {
                    if (G[i][k] + G[k][j] < G[i][j])
                    {
                        G[i][j] = G[i][k] + G[k][j];
                    }
                }
            }
        }
    }

    void FindMinAnimal()
    {
        int dist = -1;
        for (int i = 1; i <= Nv; ++i)
        {
            dist = FindMaxdist(i);
            if (dist < minAnimal.length)
            {
                minAnimal.animal = i;
                minAnimal.length = dist;
            }
        }
        if (minAnimal.length == INFINITY)
        {
            cout << 0;
            return;
        }
        else
        {
            cout << minAnimal.animal << ' ' << minAnimal.length;
            return;
        }
    }
};

int main()
{
    Graph G;
    G.BuildGraph();
    G.Floyd();
    G.FindMinAnimal();
    return 0;
}
