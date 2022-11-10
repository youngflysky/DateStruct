// TITLE:Root Of AVL Tree--平衡二叉树的调整【难！！！】--直接调整法
// READ:平衡二叉树根据其两位发明者的名字的缩写又称为 AVL ;
// NOTE:在插入新节点的过程中，插入函数是一种后序遍历递归，
// NOTE:故首次发现的非平衡二叉树根节点一定是第一颗被破坏的子二叉树;
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

typedef struct AVL_Node *BinTree, TNode;
struct AVL_Node
{
    int val;
    BinTree left;
    BinTree right;

    AVL_Node(int x) : val(x), left(NULL), right(NULL){};
};

// READ:求树的深度函数
int GetHeight(BinTree T)
{
    if (T)
    {
        int HL = GetHeight(T->left);
        int HR = GetHeight(T->right);
        return (HL > HR ? HL : HR) + 1;
    }
    else
    {
        return 0;
    }
}

// NOTE:val > T->right->val 一定是RR调整;
BinTree RR_Adjust(BinTree T)
{
    BinTree R = T->right;
    T->right = R->left;
    R->left = T;
    return R;
}

// NOTE:val < T->left->val 一定是LL调整;
BinTree LL_Adjust(BinTree T)
{
    BinTree L = T->left;
    T->left = L->right;
    L->right = T;
    return L;
}

// NOTE:val > T->left->val 一定是LR调整;
BinTree LR_Adjust(BinTree T)
{
    BinTree L = T->left;
    BinTree LR = L->right;
    T->left = LR->right, L->right = LR->left;
    LR->left = L, LR->right = T;
    return LR;
}

// NOTE:val < T->right->val 一定是RL调整;
BinTree RL_Adjust(BinTree T)
{
    BinTree R = T->right;
    BinTree RL = R->left;
    T->right = RL->left, R->left = RL->right;
    RL->left = T, RL->right = R;
    return RL;
}

// READ: AVL 在节点插入的同时实时维护 AVL 的平衡;
BinTree AVL_Insert(int val, BinTree T)
{
    if (!T)
    {
        T = new TNode(val);
    }
    else if (val > T->val)
    {
        T->right = AVL_Insert(val, T->right);
        // NOTE:新插入节点在右子树上，所以一定是右子树深度大于左子树
        if (GetHeight(T->right) - GetHeight(T->left) == 2)
        {
            if (val < T->right->val) // README:RL
            {
                T = RL_Adjust(T);
            }
            else if (val > T->right->val) // README:RR
            {
                T = RR_Adjust(T);
            }
        }
    }
    else if (val < T->val)
    {
        // READ:新插入节点在右子树上，所以一定是左子树深度大于右子树
        T->left = AVL_Insert(val, T->left);
        if (GetHeight(T->left) - GetHeight(T->right) == 2)
        {
            if (val < T->left->val) // README:LL
            {
                T = LL_Adjust(T);
            }
            else if (val > T->left->val) // README:LR
            {
                T = LR_Adjust(T);
            }
        }
    }
    return T;
}

BinTree Create_AVL() //建树函数
{
    int N;
    cin >> N;
    int val = 0;
    BinTree avl = NULL;
    for (int i = 0; i < N; ++i)
    {
        cin >> val;
        avl = AVL_Insert(val, avl);
    }
    return avl;
}

void DeleteBT(BinTree T) // READ:后序遍历释放内存
{
    if (T)
    {
        DeleteBT(T->left);
        DeleteBT(T->right);
        delete T;
    }
    return;
}

void Solution()
{

    BinTree AVL = Create_AVL();
    cout << AVL->val;
    DeleteBT(AVL);
}

int main()
{
    Solution();
    return 0;
}