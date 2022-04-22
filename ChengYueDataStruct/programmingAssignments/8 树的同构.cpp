#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct TNode //二叉树节点定义
{
    char ch;
    struct TNode *left;
    struct TNode *right;
} TNode, *BinTree;

BinTree Insert(char ch) //插入新节点
{
    BinTree T;
    T = new TNode;
    T->ch = ch;
    T->left = NULL;
    T->right = NULL;
    return T;
}

typedef struct ReadNode //节点编号数组节点
{
    char ch;
    int leftIndex = -1;
    int rightIndex = -1;
} ReadNode;

ReadNode *getNode(int N) //读入所有树的节点并存进数组 NodeArray[N]
{
    ReadNode *NodeArray;
    NodeArray = new ReadNode[N];
    char l, r;
    for (int i = 0; i < N; ++i)
    {
        cin >> NodeArray[i].ch >> l >> r;
        if (l != '-')
        {
            NodeArray[i].leftIndex = l - '0';
        }
        if (r != '-')
        {
            NodeArray[i].rightIndex = l - '0';
        }
    }
    return NodeArray;
}

BinTree buildTree(const ReadNode *readArray, int N) //建树
{
    TNode *TArray;
    TArray = new TNode[N];
    for (int i = 0; i < N; ++i)
    {
        TArray[i].ch = readArray[i].ch;
    }
    int *p;
    p = new int[N];
    for (int i = 0; i < N; ++i)
    {
        p[i] = 1;
    }
    for (int i = 0; i < N; ++i)
    {
        if (readArray[i].leftIndex != -1)
        {
            TArray[i].left = &TArray[readArray[i].leftIndex];
            p[readArray[i].leftIndex] = 0;
        }
        if (readArray[i].rightIndex != -1)
        {
            TArray[i].right = &TArray[readArray[i].rightIndex];
            p[readArray[i].rightIndex] = 0;
        }
    }
    for (int i = 0; i < N; ++i)
    {
        if (p[i])
        {
            return &TArray[i];
        }
    }
}

bool isSameStruct(const BinTree T1, BinTree T2)
{
    if (T1 && T2)
    {
        if (T1->ch != T2->ch)
        {
            return false;
        }
        else
        {
            if (isSameStruct(T1->left, T2->left))
            {
                if (isSameStruct(T1->right, T2->right))
                {
                    return true;
                }
            }
            else if (isSameStruct(T1->left, T2->right))
            {
                if (isSameStruct(T1->right, T2->left))
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
    }
    else if (!T1 && !T2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int N1;
    cin >> N1;
    ReadNode *readArray1;
    readArray1 = getNode(N1);
    BinTree T1;
    T1 = buildTree(readArray1, N1);

    int N2;
    cin >> N2;
    ReadNode *readArray2;
    readArray2 = getNode(N2);
    BinTree T2;
    T2 = buildTree(readArray2, N2);

    if (isSameStruct(T1, T2))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}