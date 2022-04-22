// README:������������Ӧ��

#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct TreeNode //�������ڵ㶨��
{
    int Data;
    struct TreeNode *Left;
    struct TreeNode *Right;
} TNode, *BinTree;
BinTree Insert(int data) //�������ڵ�Ĳ���
{
    BinTree BT;
    BT = (BinTree)malloc(sizeof(TNode));
    BT->Data = data;
    BT->Left = NULL;
    BT->Right = NULL;
    return BT;
}
BinTree CreatBinTree() //��ʼ��������
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

// 1�������������Ҷ�ӽ��
void preOrederPrintLeaves(BinTree BT)
{
    if (BT)
    {
        if (!BT->Left && !BT->Right)
        {
            cout << BT->Data;
        }
        preOrederPrintLeaves(BT->Left);
        preOrederPrintLeaves(BT->Right);
    }
}

// 2������������ĸ߶�
int PostOrederPrintHight(BinTree BT)
{
    if (BT)
    {
        int HL = PostOrederPrintHight(BT->Left);
        int HR = PostOrederPrintHight(BT->Right);
        int maxH = (HL > HR) ? HL : HR;
        return maxH + 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    BinTree bt = CreatBinTree();
    preOrederPrintLeaves(bt);
    cout << endl
         << PostOrederPrintHight(bt);

    return 0;
}