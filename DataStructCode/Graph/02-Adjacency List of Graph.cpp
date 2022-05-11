#include <iostream>
using namespace std;
#define MaxSize 1000

// NOTE:邻接表存储图：每个顶点存储该点所有出边;
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
// NOTE:逆邻接表：在每个顶点存储该点所有入边;

// NOTE:邻接多重表存储图;
typedef struct ArcEdeg
{
    int start;
    int end;
    struct ArcEdge *nextIn;  //指向下一条入边;
    struct ArcEdge *nextOut; //指向下一条出边;
} ArcEdeg;
typedef struct
{
    char data; //顶点信息;
    ArcEdeg *firstIn;
    ArcEdeg *firstOut;
} V_Node;
typedef struct
{
    V_Node adjlist[MaxSize];
    int n, e;
} A_Graph;