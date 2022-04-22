#include <cstdlib>
#include <iostream>
using namespace std;
#define maxSize 101

typedef struct TreeNode //二叉树节点定义
{
    int Data;
    struct TreeNode *Left;
    struct TreeNode *Right;
} TNode, *BinTree;
BinTree Insert(int data) //二叉树节点的插入
{
    BinTree BT;
    BT = (BinTree)malloc(sizeof(TNode));
    BT->Data = data;
    BT->Left = NULL;
    BT->Right = NULL;
    return BT;
}
BinTree CreatBinTree() //初始化二叉树
{
    BinTree BT;
    BT = (BinTree)malloc(sizeof(struct TreeNode));
    BT->Data = 1;
    BT->Left = Insert(2);
    BT->Right = Insert(3);
    BT->Left->Left = Insert(4);
    BT->Left->Right = Insert(6);
    BT->Left->Right->Left = Insert(5);
    BT->Right->Left = Insert(7);
    BT->Right->Right = Insert(9);
    BT->Right->Left->Right = Insert(8);
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

typedef struct StackNode //链栈节点定义
{
    BinTree T;
    struct StackNode *Next;
} StackNode, *Stack;
Stack CreatStack() //链栈初始化；
{
    Stack s;
    s = (Stack)malloc(sizeof(StackNode));
    s->Next = NULL;
    return s;
}
bool isEmpty(Stack S1) //判断栈是否为空
{
    if (S1->Next)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Push(Stack S1, BinTree T) //入栈
{
    for (; S1->Next; S1 = S1->Next)
        ;
    Stack newS = CreatStack();
    newS->T = T;
    S1->Next = newS;
    return;
}
BinTree Pop(Stack S1) //出栈
{
    Stack q = S1;
    S1 = S1->Next;
    for (; S1->Next; q = S1, S1 = S1->Next)
        ;
    BinTree T = S1->T;
    q->Next = NULL;
    free(S1);
    return T;
}

// 1、非递归算法实现中序遍历
void InOrderTraversalNo_recursive1(BinTree BT) //路线法
{
    if (BT)
    {
        BinTree T = BT;
        BinTree stack[maxSize];
        int top = -1;
        while (T || top > -1)
        {
            while (T)
            {
                stack[++top] = T;
                T = T->Left;
            }
            if (top > -1)
            {
                T = stack[top--];
                cout << T->Data;
                T = T->Right;
            }
        }
    }
}

// 2、非递归算法实现先序遍历
void PreOrderTraversalNo_recursive1(BinTree BT) //路线法
{
    if (BT)
    {
        BinTree stack[maxSize];
        int top = -1;
        BinTree T = BT;
        while (T || top > -1)
        {
            while (T)
            {
                cout << T->Data;
                stack[++top] = T;
                T = T->Left;
            }
            if (top > -1)
            {
                T = stack[top--];

                T = T->Right;
            }
        }
    }
    //链栈实现
    // BinTree T = BT;
    // Stack S1 = CreatStack();
    // while (T || isEmpty(S1))
    // {
    //     while (T)
    //     {
    //         cout << T->Data;
    //         Push(S1, T);
    //         T = T->Left;
    //     }
    //     if (isEmpty(S1))
    //     {
    //         T = Pop(S1);
    //         T = T->Right;
    //     }
    // }
}

void PreOrderTraversalNo_recursive2(BinTree BT) //模拟法
{
    if (BT)
    {
        BinTree stack[maxSize];
        int top = -1;
        BinTree T = NULL;
        stack[++top] = BT;
        while (top > -1)
        {
            T = stack[top--];
            cout << T->Data;
            if (T->Right) //左右孩子的入栈顺序和访问顺序相反
            {
                stack[++top] = T->Right;
            }
            if (T->Left)
            {
                stack[++top] = T->Left;
            }
        }
    }
}

// 3、非递归算法实现后序遍历
void PostOrderTraversalNo_recursive1(BinTree BT) //路线法
{
    if (BT)
    {
        BinTree stack[maxSize];
        int top = -1;
        BinTree T = BT;
        BinTree pre = NULL;
        while (T || top > -1)
        {
            while (T)
            {
                stack[++top] = T;
                T = T->Left;
            }
            if (top > -1)
            {
                T = stack[top--];
                if (!T->Right || pre == T->Right)
                {
                    cout << T->Data;
                    pre = T;
                    T = NULL;
                }
                else
                {
                    stack[++top] = T;
                    T = T->Right;
                }
            }
        }
    }
}

void PostOrderTraversalNo_recursive2(BinTree BT) //模拟法+逆后续
{
    if (BT)
    {
        BinTree stack[maxSize];
        int top = -1;
        BinTree ReverseStack[maxSize];
        int ReverseTop = -1;
        BinTree T;
        stack[++top] = BT;
        while (top > -1)
        {
            T = stack[top--];
            ReverseStack[++ReverseTop] = T;
            if (T->Left)
            {
                stack[++top] = T->Left;
            }
            if (T->Right)
            {
                stack[++top] = T->Right;
            }
        }
        while (ReverseTop > -1)
        {
            cout << ReverseStack[ReverseTop--]->Data;
        }
    }
}

// 4、层次遍历
void LevelOrderTraversal(BinTree BT)
{
    if (!BT)
    {
        return;
    }
    BinTree queue[maxSize];
    int front = 0, rear = 0;
    BinTree T = BT;
    rear = (rear + 1) % maxSize;
    queue[rear] = T;
    while (rear != front)
    {
        front = (front + 1) % maxSize;
        T = queue[front];
        cout << T->Data;
        if (T->Left)
        {
            rear = (rear + 1) % maxSize;
            queue[rear] = T->Left;
        }
        if (T->Right)
        {
            rear = (rear + 1) % maxSize;
            queue[rear] = T->Right;
        }
    }
}

int main()
{
    BinTree bt = CreatBinTree();
    cout << "\nInOrderRraversal(route method):" << endl;
    InOrderTraversalNo_recursive1(bt);
    cout << endl
         << "simulation method isn't suitable for InOrderTraversal";
    cout << endl
         << endl
         << "PreOrderTraversal(route method):" << endl;
    PreOrderTraversalNo_recursive1(bt);
    cout << endl
         << "PreOrderTraversal(simulation method):" << endl;
    PreOrderTraversalNo_recursive2(bt);
    cout << endl
         << endl
         << "PostOrderTraversal(route method - single stack):" << endl;
    PostOrderTraversalNo_recursive1(bt);
    cout << endl
         << "PostOrderTraversal(simulation method + double stack):" << endl;
    PostOrderTraversalNo_recursive2(bt); //逆后续
    cout << endl
         << endl
         << "LevelOrderTraversal(Queue):" << endl;
    LevelOrderTraversal(bt);

    return 0;
}