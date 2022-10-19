#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

typedef struct TreeNode *BinTree;
struct TreeNode
{
    int data;      // 存值
    BinTree left;  // 左儿子结点
    BinTree right; // 右儿子结点
};
BinTree CreatBinTree();              // 创建一个二叉树
BinTree Insert(int val);             //插入一个节点;
bool IsEmpty(BinTree BT);            // 判断树 BT 是否为空
void PreOrderTraversal(BinTree BT);  // 先序遍历，根左右
void InOrderTraversal(BinTree BT);   // 中序遍历，左根右
void PostOrderTraversal(BinTree BT); // 后序遍历，左右根

//插入一个节点;
BinTree Insert(int val)
{
    BinTree TNode = (BinTree)malloc(sizeof(TreeNode));
    TNode->left = TNode->right = NULL;
    TNode->data = val;
    return TNode;
}

// 初始化二叉树
BinTree CreatBinTree()
{
    BinTree BT;
    BT = (BinTree)malloc(sizeof(struct TreeNode));
    BT->data = 1;
    BT->left = Insert(2);
    BT->right = Insert(3);
    BT->left->left = Insert(4);
    BT->left->right = Insert(6);
    BT->left->right->left = Insert(5);
    BT->right->left = Insert(7);
    BT->right->right = Insert(9);
    BT->right->left->right = Insert(8);
    return BT;
}

/*
                 1
               /   \
              2     3
             / \    / \
            4   6  7   9
               /    \
              5      8
*/

// 先序非递归
void PreOrderTraversal(BinTree BT) //路线法;
{
    if (!BT)
    {
        return;
    }
    stack<BinTree> S;
    BinTree T = BT;
    while (T || !S.empty())
    {
        while (T)
        {
            S.push(T);
            T = T->left;
        }
        if (!S.empty())
        {
            T = S.top(), S.pop();
            cout << T->data;
            T = T->right;
        }
    }
}

// 先序非递归
void PreOrderTraversal_Simulation(BinTree BT) //模拟法;
{
    if (!BT)
    {
        return;
    }
    stack<BinTree> S;
    BinTree T = BT;
    S.push(T);
    while (!S.empty())
    {
        T = S.top(), S.pop();
        cout << T->data;
        if (T->right)
        {
            S.push(T->right);
        }
        if (T->left)
        {
            S.push(T->left);
        }
    }
}

/*
                 1
               /   \
              2     3
             / \    / \
            4   6  7   9
               /    \
              5      8
*/

// 中序非递归
void InOrderTraversal(BinTree BT) //路线法;
{
    if (!BT)
    {
        return;
    }
    stack<BinTree> S;
    BinTree T = BT;
    while (T || !S.empty())
    {
        while (T)
        {
            cout << T->data;
            S.push(T);
            T = T->left;
        }
        if (!S.empty())
        {
            T = S.top(), S.pop();
            T = T->right;
        }
    }
}

/*
                 1
               /   \
              2     3
             / \    / \
            4   6  7   9
               /    \
              5      8
*/

// 后序非递归
void PostOrderTraversal(BinTree BT) //路线法;
{
    if (!BT)
    {
        return;
    }
    stack<BinTree> S;
    BinTree Pre = NULL;
    BinTree T = BT;
    while (T || !S.empty())
    {
        while (T)
        {
            S.push(T);
            T = T->left;
        }
        if (!S.empty())
        {
            T = S.top(), S.pop();
            if ((!T->right) || Pre == T->right)
            {
                cout << T->data;
                Pre = T;
                T = NULL;
            }
            else
            {
                S.push(T);
                T = T->right;
            }
        }
    }
}

void PostOrderTraversal_Simulation(BinTree BT) //模拟法;
{
    if (!BT)
    {
        return;
    }
    stack<BinTree> sta;
    stack<BinTree> rev_sta;
    BinTree T = BT;
    sta.push(T);
    while (!sta.empty())
    {
        T = sta.top(), sta.pop();
        rev_sta.push(T);
        if (T->left)
        {
            sta.push(T->left);
        }
        if (T->right)
        {
            sta.push(T->right);
        }
    }
    while (!rev_sta.empty())
    {
        cout << rev_sta.top()->data, rev_sta.pop();
    }
}

/*
                 1
               /   \
              2     3
             / \    / \
            4   6  7   9
               /    \
              5      8
*/

// 层次遍历
void LevelOrderTraversal(BinTree BT)
{
    if (!BT)
    {
        return;
    }
    queue<BinTree> que;
    BinTree T = BT;
    que.push(T);
    while (!que.empty())
    {
        T = que.front(), que.pop();
        cout << T->data;
        if (T->left)
        {
            que.push(T->left);
        }
        if (T->right)
        {
            que.push(T->right);
        }
    }
}

/*
                 1
               /   \
              2     3
             / \    / \
            4   6  7   9
               /    \
              5      8
*/

// 输出叶子结点
void FindLeaves(BinTree BT)
{
    if (!BT)
    {
        return;
    }
    if (!BT->left && !BT->right)
    {
        cout << BT->data;
    }
    FindLeaves(BT->left);
    FindLeaves(BT->right);
}

// 求树高度
int GetHeight(BinTree BT)
{
    if (!BT)
    {
        return 0;
    }
    int leftH = GetHeight(BT->left);
    int rightH = GetHeight(BT->right);
    return leftH > rightH ? leftH + 1 : rightH + 1;
}

int main()
{
    BinTree BT;
    BT = CreatBinTree();
    cout << "PreOTra: ";
    PreOrderTraversal(BT);
    cout << "\nInOrTra: ";
    PreOrderTraversal_Simulation(BT);
    cout << "\nInSiTra: ";
    InOrderTraversal(BT);
    cout << "\nPostTra: ";
    PostOrderTraversal(BT);
    cout << "\nPoSiTra: ";
    PostOrderTraversal_Simulation(BT);
    cout << "\nLevTra: ";
    LevelOrderTraversal(BT);
    cout << "\nListLeaves: ";
    FindLeaves(BT);
    cout << "\nPutHeight: " << GetHeight(BT);
    return 0;
}
