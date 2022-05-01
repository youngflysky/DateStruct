// TITLE:Root Of AVL Tree
#include <iostream>
#include <vector>
using namespace std;

typedef struct TNode *BinTree;
typedef struct TNode
{
    int data;
    BinTree father;
    BinTree left;
    BinTree right;
} TNode;

bool IsLeaves(BinTree BST)
{
    if (!BST)
    {
        return true;
    }
    if (!BST->right && !BST->left)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsAVL(BinTree BST) //判断是否是平衡二叉树
{
    if (!BST)
    {
        return true;
    }
    else if (IsLeaves(BST))
    {
        return true;
    }
    else if (!BST->right)
    {
        if (IsLeaves(BST->left))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (!BST->left)
    {
        if (IsLeaves(BST->right))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (IsLeaves(BST->left))
    {
        if (IsLeaves(BST->right->left) && IsLeaves(BST->right->right))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (IsLeaves(BST->right))
    {
        if (IsLeaves(BST->left->left) && IsLeaves(BST->left->right))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return (IsAVL(BST->left) && IsAVL(BST->right));
    }
}

void ReBanlanceAVL(BinTree &BST) //调整平衡二叉树;
{
    if (!BST)
    {
        return;
    }
    if (BST->left && !BST->right)
    {
        if (BST->left->left)
        {
            BinTree Root = BST->left;
            BST->left->father = BST->father;
            BST->left->right = BST;
            BST->left = NULL;
            BST = Root;
        }
        else
        {
            BinTree Temp = BST->left->right;
            BinTree Root = BST->left;
            Root->left = BST;
            Root->right = BST->father;
            Root->father = BST->father->father;
            Root->left->father = Root->right->father = Root;
            Root->right->left = Root->left->left = NULL;
            Root->left->right = Temp;
        }
    }
    else if (BST->right && !BST->left)
    {
        if (BST->right->left)
        {
            BinTree Temp = BST->right->left;
            BinTree Root = BST->right;
            Root->right = BST;
            Root->left = BST->father;
            Root->father = BST->father->father;
            Root->left->father = Root->right->father = Root;
            Root->right->right = Root->left->right = NULL;
            Root->right->left = Temp;
        }
        else
        {
            BinTree Root = BST->right;
            BST->right->father = BST->father;
            BST->right->left = BST;
            BST->right = NULL;
            BST = Root;
        }
    }
    else
    {
        ReBanlanceAVL(BST->left);
        ReBanlanceAVL(BST->right);
    }
}

BinTree Insert(int data, BinTree BST) // NOTE:平衡二叉树节点插入时，增加一个 父指针 指向 父节点，根节点父指针为空
{
    if (!BST)
    {
        BST = new TNode;
        BST->father = BST->left = BST->right = NULL;
        BST->data = data;
    }
    else if (data > BST->data)
    {
        BST->right = Insert(data, BST->right);
        BST->right->father = BST;
    }
    else if (data < BST->data)
    {
        BST->left = Insert(data, BST->left);
        BST->left->father = BST;
    }
    return BST;
}

BinTree CreateBST() //建树函数
{
    int N;
    cin >> N;
    int data;
    BinTree BST = NULL;
    for (int i = 0; i < N; ++i)
    {
        cin >> data;
        BST = Insert(data, BST);
        if (!IsAVL(BST))
        {
            ReBanlanceAVL(BST);
        }
    }
    return BST;
}

void DeleteBT(BinTree BST) //释放BST;
{
    if (BST)
    {
        DeleteBT(BST->left);
        DeleteBT(BST->right);
        delete BST;
        BST = NULL;
    }
    return;
}

int main()
{
    BinTree BST = CreateBST();
    cout << BST->data;
    DeleteBT(BST);
    return 0;
}