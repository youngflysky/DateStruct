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
    int data;      // ��ֵ
    BinTree left;  // ����ӽ��
    BinTree right; // �Ҷ��ӽ��
};
BinTree CreatBinTree();              // ����һ��������
BinTree Insert(int val);             //����һ���ڵ�;
bool IsEmpty(BinTree BT);            // �ж��� BT �Ƿ�Ϊ��
void PreOrderTraversal(BinTree BT);  // ���������������
void InOrderTraversal(BinTree BT);   // ��������������
void PostOrderTraversal(BinTree BT); // ������������Ҹ�

//����һ���ڵ�;
BinTree Insert(int val)
{
    BinTree TNode = (BinTree)malloc(sizeof(TreeNode));
    TNode->left = TNode->right = NULL;
    TNode->data = val;
    return TNode;
}

// ��ʼ��������
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

// ����ǵݹ�
void PreOrderTraversal(BinTree BT) //·�߷�;
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

// ����ǵݹ�
void PreOrderTraversal_Simulation(BinTree BT) //ģ�ⷨ;
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

// ����ǵݹ�
void InOrderTraversal(BinTree BT) //·�߷�;
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

// ����ǵݹ�
void PostOrderTraversal(BinTree BT) //·�߷�;
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

void PostOrderTraversal_Simulation(BinTree BT) //ģ�ⷨ;
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

// ��α���
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

// ���Ҷ�ӽ��
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

// �����߶�
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
