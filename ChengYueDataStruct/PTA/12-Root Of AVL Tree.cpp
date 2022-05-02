// TITLE:Root Of AVL Tree
#include <iostream>
#include <vector>
using namespace std;

typedef class AVL_Node *BinTree, TNode;
class AVL_Node
{
public:
    int data;
    BinTree left;
    BinTree right;
    int height;

public:
    AVL_Node(int x) : data(x), left(NULL), right(NULL), height(0){};
};

// NOTE:求树的深度函数
int GetHeight(BinTree T)
{
    if (T)
    {
        int HL = GetHeight(T->left);
        int HR = GetHeight(T->right);
        int MaxH = (HL > HR) ? HL : HR;
        return MaxH + 1;
    }
    else
    {
        return 0;
    }
}

// NOTE:RR调整【 左单旋转 】
BinTree SingleLeftRotation(BinTree T)
{
    /*
            T
             \
              B
             / \
                 C
    */
    // 此时根节点是 T
    BinTree Root = T->right;
    T->right = Root->left;
    Root->left = T;
    T->height = GetHeight(T);
    Root->height = GetHeight(Root);
    return Root;
    /*
        B
       / \
      T   C
       \
    */
}

// NOTE:LL调整【 右单旋转 】
BinTree SingleRightRotation(BinTree T)
{
    /*
            T
           /
          B
         / \
        C
    */
    // 此时根节点是 A
    BinTree Root = T->left;
    T->left = Root->right;
    Root->right = T;
    T->height = GetHeight(T);
    Root->height = GetHeight(Root);
    return Root;
    /*
        B
       / \
      C   T
         /
    */
}

// NOTE:LR调整【先左后右双旋转】
BinTree DoubleLeftRightRotation(BinTree T)
{
    T->left = SingleLeftRotation(T->left);
    return SingleRightRotation(T);
}

// NOTE:RL调整【先右后左双旋转】
BinTree DoubleRightLeftRotation(BinTree T)
{
    T->right = SingleRightRotation(T->right);
    return SingleLeftRotation(T);
}

// NOTE: AVL 在节点插入的同时实时维护 AVL 的平衡;

BinTree AVL_Insert(int data, BinTree T)
{
    if (!T)
    {
        T = new TNode(data);
    }
    else if (data > T->data)
    {
        T->right = AVL_Insert(data, T->right);
        // NOTE:新插入节点在右子树上，所以一定是右子树深度大于左子树
        if (GetHeight(T->right) - GetHeight(T->left) == 2)
        {
            if (data < T->right->data) // README:RL
            {
                T = DoubleRightLeftRotation(T);
            }
            else if (data > T->right->data) // README:RR
            {
                T = SingleLeftRotation(T);
            }
        }
    }
    else if (data < T->data)
    {
        // NOTE:新插入节点在右子树上，所以一定是左子树深度大于右子树
        T->left = AVL_Insert(data, T->left);
        if (GetHeight(T->left) - GetHeight(T->right) == 2)
        {
            if (data < T->left->data) // README:LL
            {
                T = SingleRightRotation(T);
            }
            else if (data > T->left->data) // README:LR
            {
                T = DoubleLeftRightRotation(T);
            }
        }
    }
    T->height = GetHeight(T);
    return T;
}

BinTree Create_AVL() //建树函数
{
    int N;
    cin >> N;
    int data = 0;
    BinTree avl = NULL;
    for (int i = 0; i < N; ++i)
    {
        cin >> data;
        avl = AVL_Insert(data, avl);
    }
    return avl;
}
void DeleteBT(BinTree T) //后序遍历释放内存
{
    if (T)
    {
        DeleteBT(T->left);
        DeleteBT(T->right);
        delete T;
    }
    return;
}

int main()
{
    BinTree AVL = Create_AVL();
    cout << AVL->data;
    return 0;
}