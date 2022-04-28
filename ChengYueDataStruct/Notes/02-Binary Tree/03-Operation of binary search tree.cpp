// TITLE: Operation of binary search tree.cpp

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
typedef int ElementType;
typedef struct TreeNode *BinTree;
struct TreeNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void InOrderTraversal(BinTree BST) //中序遍历;
{
    if (!BST)
    {
        return;
    }
    else
    {
        InOrderTraversal(BST->Left);
        cout << BST->Data << " ";
        InOrderTraversal(BST->Right);
    }
}

//查找递归实现 NOTE:这是一个尾递归函数，效率低，改用循环实现更合适
BinTree Find(ElementType X, BinTree BST)
{
    if (!BST)
    {
        return NULL;
    }
    if (X < BST->Data)
    {
        return Find(X, BST->Left);
    }
    else if (X > BST->Data)
    {
        return Find(X, BST->Right);
    }
    else
    {
        return BST;
    }
}

//查找非递归实现
BinTree IterFind(ElementType X, BinTree BST)
{
    while (BST)
    {
        if (X > BST->Data)
        {
            BST = BST->Right;
        }
        if (X < BST->Data)
        {
            BST = BST->Left;
        }
        else
        {
            return BST;
        }
    }
    return NULL;
}

// 查找最小值的递归实现
BinTree FindMin(BinTree BST)
{
    if (!BST) // 如果为空了，返回 NULL
        return NULL;
    else if (BST->Left) // 还存在左子树，沿左分支继续查找
        return FindMin(BST->Left);
    else // 找到了
        return BST;
}

// 查找最大值的非递归实现
BinTree FindMax(BinTree BST)
{
    if (BST)               // 如果不空
        while (BST->Right) // 只要右子树还存在
            BST = BST->Right;
    return BST;
}

// NOTE: BST Insert 重难点
BinTree Insert(ElementType X, BinTree BST) // README:传入指针
{
    if (!BST)
    {
        BST = new struct TreeNode;
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    if (X > BST->Data)
    {
        BST->Right = Insert(X, BST->Right);
    }
    else if (X < BST->Data)
    {
        BST->Left = Insert(X, BST->Left);
    }
    return BST;
}

bool Insert(BinTree &BST, ElementType X) // README:传入指针的引用
{
    if (!BST)
    {
        BST = new struct TreeNode;
        BST->Left = BST->Right = NULL;
        BST->Data = X;
        return true;
    }
    if (X == BST->Data)
    {
        return false; //插入元素已存在 BST 中
    }
    else if (X > BST->Data)
    {
        return Insert(BST->Right, X);
    }
    else
    {
        return Insert(BST->Left, X);
    }
}

// NOTE:构建 BST
BinTree CreateBST()
{
    int N;
    cin >> N;
    if (N <= 0)
    {
        return NULL;
    }
    BinTree BST;
    ElementType Data;
    for (int i = 0; i < N; ++i)
    {
        cin >> Data;
        BST = Insert(Data, BST);
    }
    return BST;
}

// NOTE:删除指定节点
BinTree Delete(ElementType X, BinTree BST)
{
    if (!BST)
    {
        cout << "The element to delete was not found！\n";
        return NULL;
    }
    else if (X < BST->Data)
    {
        BST->Left = Delete(X, BST->Left);
    }
    else if (X > BST->Data)
    {
        BST->Right = Delete(X, BST->Right);
    }
    else
    {
        BinTree Temp;
        if (BST->Left && BST->Right)
        {
            Temp = FindMin(BST->Right);
            BST->Data = Temp->Data;
            BST->Right = Delete(Temp->Data, BST->Right);
        }
        else
        {
            Temp = BST;
            if (!BST->Left)
            {
                BST = BST->Right;
            }

            else
            {
                BST = BST->Left;
            }
            delete Temp;
        }
    }
    return BST;
}

int main()
{
    BinTree BST = CreateBST();
    int a;
    srand((unsigned)time(NULL));
    a = (rand() % 9 + 1);
    /*
                5
               /\
              3  7
             /\	 /\
            1 4 6  8
            \      \
             2      9
    */
    cout << "中序遍历的结果是：";
    InOrderTraversal(BST);
    cout << endl;
    cout << "查找最小值是：" << FindMin(BST)->Data << endl;
    cout << "查找最大值是：" << FindMax(BST)->Data << endl;
    cout << "查找值为3的结点左子树结点值为：" << Find(3, BST)->Left->Data << endl;
    cout << "查找值为7的结点右子树结点值为：" << IterFind(7, BST)->Right->Data << endl;
    cout << "删除值为" << a << "的结点" << endl;
    Delete(a, BST);
    /*
                6
               /\
              3  7
             /\	  \
            1 4    8
            \      \
             2      9
    */
    cout << "中序遍历的结果是：";
    InOrderTraversal(BST);
    cout << endl;
    return 0;
}