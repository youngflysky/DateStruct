// TITLE:是否是同一棵二叉搜索树
#include <iostream>
#include <vector>
using namespace std;

int N, L;
bool Switch()
{
    cin >> N;
    if (N)
    {
        cin >> L;
        return true;
    }
    else
    {
        return false;
    }
}

typedef struct TreeNode *BinTree;
typedef struct TreeNode // BST 节点
{
    int Data;
    BinTree Left;
    BinTree Right;
} TNode;

bool BinaryInsert(int data, BinTree &BST) // BST 节点插入，失败返回 false
{
    if (!BST)
    {
        BST = new TNode();
        BST->Data = data;
        BST->Left = BST->Right = NULL;
        return true;
    }
    if (data > BST->Data)
    {
        return BinaryInsert(data, BST->Right);
    }
    else if (data < BST->Data)
    {
        return BinaryInsert(data, BST->Left);
    }
    else
    {
        return false;
    }
}

BinTree CreateBST() // BST 建树
{
    BinTree BST = NULL;
    int key = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> key;
        BinaryInsert(key, BST);
    }
    return BST;
}

bool IsSameBST(const BinTree BST, const BinTree initialBST) //先序遍历确定是否是同一棵BST;
{
    if (!BST && !initialBST)
    {
        return true;
    }
    else if (!BST || !initialBST)
    {
        return false;
    }
    else if (BST->Data != initialBST->Data)
    {
        return false;
    }
    else
    {
        return (IsSameBST(BST->Left, initialBST->Left) && IsSameBST(BST->Right, initialBST->Right));
    }
}

int main()
{
    vector<bool> result; // NOTE: vector 容器储存结果！！！
    BinTree initialBST = NULL;
    BinTree BST = NULL;
    while (Switch())
    {
        initialBST = CreateBST();
        for (int i = 1; i <= L; ++i)
        {
            BST = CreateBST();
            result.push_back(IsSameBST(BST, initialBST));
        }
    }
    for (int i = 0; i < result.size(); ++i)
    {
        if (result[i])
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}