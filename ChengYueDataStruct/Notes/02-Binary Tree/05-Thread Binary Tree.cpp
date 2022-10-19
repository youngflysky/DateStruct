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
    int lTag, rTag;
};
BinTree CreatBinTree();  // 创建一个二叉树
BinTree Insert(int val); //插入一个节点;

//插入一个节点;
BinTree Insert(int val)
{
    BinTree TNode = (BinTree)malloc(sizeof(TreeNode));
    TNode->left = TNode->right = NULL;
    TNode->lTag = TNode->rTag = 0;
    TNode->data = val;
    return TNode;
}

// 初始化二叉树
BinTree CreatBinTree()
{
    BinTree BT;
    BT = (BinTree)malloc(sizeof(struct TreeNode));
    BT->data = 1;
    BT->lTag = BT->rTag = 0;
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

void InOrderTraversal(BinTree BT)
{
    if (!BT)
    {
        return;
    }
    InOrderTraversal(BT->left);
    cout << BT->data;
    InOrderTraversal(BT->right);
}

void InThread(BinTree p, BinTree &pre)
{
    if (!p)
    {
        return;
    }
    InThread(p->left, pre);
    if (!p->left)
    {
        p->left = pre;
        p->lTag = 1;
    }
    if (pre && !pre->right)
    {
        pre->right = p;
        pre->rTag = 1;
    }
    pre = p;
    InThread(p->right, pre);
}

void CreateInthreadBT(BinTree BT)
{
    if (!BT)
    {
        return;
    }
    BinTree pre = NULL;
    InThread(BT, pre);
    pre->right = NULL;
    pre->rTag = 1;
}
// NOTE:中序线索二叉树;

void PreOrderTraversal(BinTree BT)
{
    if (!BT)
    {
        return;
    }
    cout << BT->data;
    PreOrderTraversal(BT->left);
    PreOrderTraversal(BT->right);
}

void PreThread(BinTree p, BinTree &pre)
{
    if (!p)
    {
        return;
    }
    if (!p->left)
    {
        p->left = pre;
        p->lTag = 1;
    }
    if (pre && !pre->right)
    {
        pre->right = p;
        pre->rTag = 1;
    }
    pre = p;

    if (!p->lTag)
    {
        PreThread(p->left, pre);
    }
    if (!p->rTag)
    {
        PreThread(p->right, pre);
    }
}

void CreatePrethreadBT(BinTree BT)
{
    if (!BT)
    {
        return;
    }
    BinTree pre = NULL;
    PreThread(BT, pre);
    pre->right = NULL;
    pre->rTag = 1;
}
// NOTE:前序线索二叉树;

void PostOrderTraversal(BinTree BT)
{
    if (!BT)
    {
        return;
    }
    PostOrderTraversal(BT->left);
    PostOrderTraversal(BT->right);
    cout << BT->data;
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
void PostThread(BinTree p, BinTree &pre)
{
    if (!p)
    {
        return;
    }

    PostThread(p->left, pre);

    PostThread(p->right, pre);

    if (!p->left)
    {
        p->left = pre;
        p->lTag = 1;
    }

    if (pre && !pre->right)
    {
        pre->right = p;
        p->rTag = 1;
    }

    pre = p;
}

void CreatePostthreadBT(BinTree BT)
{
    if (!BT)
    {
        return;
    }
    BinTree pre = NULL;
    PostThread(BT, pre); // NOTE:pre 最后指向1，不需要额外线索化;
}
// NOTE:后续线索二叉树;

// READ:下面是对中序线索二叉树的遍历;
BinTree FirstNode(BinTree BT) // README:找到中序遍历的首个节点;
{
    while (!BT->lTag)
    {
        BT = BT->left;
    }
    return BT;
}

void InOrderTraInThread(BinTree BT)
{
    if (!BT)
    {
        return;
    }
    BinTree p = FirstNode(BT);
    cout << p->data;
    while (p->right)
    {
        if (p->rTag == 1)
        {
            p = p->right;
            cout << p->data;
        }
        else
        {
            p = p->right;
            while (p->lTag == 0)
            {
                p = p->left;
            }
            cout << p->data;
        }
    }
}

int main()
{

    BinTree BT;
    BT = CreatBinTree();
    InOrderTraversal(BT);
    cout << endl;
    CreateInthreadBT(BT);
    InOrderTraInThread(BT);

    // PreOrderTraversal(BT);
    // cout << endl;
    // CreatePrethreadBT(BT);

    // PostOrderTraversal(BT);
    // cout << endl;
    // CreatePostthreadBT(BT);

    return 0;
}